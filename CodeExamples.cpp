//-----------------------------------------------------------
//std::map. default value:

template<typename T, T X>
struct Default {
    Default () : val(T(X)) {}
    Default (T const & val) : val(val) {}
    operator T & () { return val; }
    operator T const & () const { return val; }
    T val;
};

std::map<KeyType, Default<ValueType, DefaultValue> > mapping;

//-----------------------------------------------------------
// observe values in map with list:

std::pair< const std::pair<Symbol, Symbol>, list<Symbol> >

What you want is something like this

auto it = parseTable.find(std::pair(stack_symbol.top(), current_symbol));

if (it != parseTable.end()) { // A match was found
    //it->first is std::pair<Symbol, Symbol>
    //it->second is list<Symbol>
    for (auto& symbol : it->second) {
        //symbol is each individual value in the list
        ... do something with symbol
    }
}

//-----------------------------------------------------------
// Get the type name in C++14 at compile time:

struct string_view
{
    char const* data;
    std::size_t size;
};

inline std::ostream& operator<<(std::ostream& o, string_view const& s)
{
    return o.write(s.data, s.size);
}

template<class T>
constexpr string_view get_name()
{
    char const* p = __PRETTY_FUNCTION__;
    while (*p++ != '=');
    for (; *p == ' '; ++p);
    char const* p2 = p;
    int count = 1;
    for (;;++p2)
    {
        switch (*p2)
        {
        case '[':
            ++count;
            break;
        case ']':
            --count;
            if (!count)
                return {p, std::size_t(p2 - p)};
        }
    }
    return {};
}

//-----------------------------------------------------------
// std::false_type:

#include <iostream>

template <typename T>
struct is_string : std::false_type {};

template<>
struct is_string<std::string> : std::true_type {};

int main() {
  std::cout << std::boolalpha
      << is_string<void>::value << '\n'
      << is_string<std::string>::value << '\n';
}

//-----------------------------------------------------------
// tuple access:

#include <iostream>
#include <vector>
#include <tuple>

using cell_type = std::tuple<int, int>;
using data_type = std::vector<cell_type>;

int main() {

    data_type s;

    s.push_back(cell_type(1,2));
    s.push_back(cell_type(2,4));
    s.push_back(cell_type(6,5));
    s.push_back(cell_type(2,1));
    s.push_back(cell_type(2,1));

    for (std::tuple<int, int> &tup : s)
        std::cout << std::get<0>(tup) << " " << std::get<1>(tup) << '\n';

    int k = 2;
    int v = 99;

    for (decltype(auto) tup : s)
    {
        if (std::get<0>(tup) == k)
        {
            std::get<1>(tup) = v;
        }
    }

    std::cout << '\n';

    for (auto &tup : s)
        std::cout << std::get<0>(tup) << " " << std::get<1>(tup) << '\n';

    return 0;
}

//-----------------------------------------------------------
// tuple comparator:

#include <iostream>
#include <set>
#include <tuple>
#include <algorithm>

using cell_type = std::tuple<std::size_t, std::size_t, int>;

struct less_compare {
    bool operator() (const cell_type& lhs, const cell_type& rhs) const
    {
        return lhs < rhs;
    }
};

using data_type = std::set<cell_type, less_compare>;

int main() {

    data_type s;

    s.insert(cell_type(1,2,3));
    s.insert(cell_type(2,4,5));
    s.insert(cell_type(6,5,3));
    s.insert(cell_type(2,1,4));
    s.insert(cell_type(2,1,5));

    std::size_t row = 2;
    std::size_t col = 4;

    auto it = std::find_if(std::begin(s), std::end(s), [&row, &col]
                           (const cell_type& el)
                           {
                               bool equal = (std::get<0>(el) == row) && (std::get<1>(el) == col);
                               return equal;
                           }
                          );

    if(it == std::end(s))
        std::cout << "last " << std::endl;
    else
        std::cout << "not last " << std::endl;

    auto el = *it;
    std::cout << std::get<0>(el) << " " << std::get<1>(el) << " " << std::get<2>(el) << std::endl;
    std::cout << std::endl;

    for (auto el : s)
        std::cout << std::get<0>(el) << " " << std::get<1>(el) << " " << std::get<2>(el) << std::endl;

    /*
    for(data_type::const_iterator i = std::begin(s); i != std::end(s); ++i)
    {
        auto el = *i;
        std::cout << std::get<0>(el) << " " << std::get<1>(el) << " " << std::get<2>(el) << std::endl;
    }
    */

    return 0;
}

//-----------------------------------------------------------
// mutexes:

#include <iostream>
#include <string>
#include <thread>
#include <map>
#include <mutex>
#include <future>

std::mutex cout_mutex;
std::mutex cerr_mutex;

using dict_t = std::map<std::string, std::string>;

std::string foo(dict_t &)
{
    std::thread::id this_id = std::this_thread::get_id();

    cout_mutex.lock();
    std::cout << "foo " << this_id << std::endl;
    cout_mutex.unlock();

    cerr_mutex.lock();
    std::cerr << "foo " << this_id << std::endl;
    cerr_mutex.unlock();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    return std::string{"ok"};
}

//thread_local int a1;
int a1;

int main()
{
    dict_t d;
    std::thread t1(foo, std::ref(d));
    std::thread t2(foo, std::ref(d));

    t1.join();
    t2.join();

    auto r1 = std::async(std::launch::async,
        foo, std::ref(d));
    std::cout << r1.get() << std::endl;

    auto r2 = std::async(std::launch::deferred,
        foo, std::ref(d));
    std::cout << r2.get() << std::endl;
}

//-----------------------------------------------------------
// condition variable notify_one:

#include <chrono>
#include <condition_variable>
#include <iostream>
#include <queue>
#include <thread>

using namespace std::chrono_literals;

std::queue<std::string> msgs;
std::condition_variable cv;
std::mutex cv_m;

void worker(std::queue<std::string> &q)
{
    std::cout << "worker. started" << std::endl;
    std::unique_lock<std::mutex> lk(cv_m);
    std::cout << "worker. before wait call" << std::endl;
    cv.wait(lk, [&q](){ std::cout << "worker. wait condition check" << std::endl; return !q.empty(); });
    std::cout << "worker. processing ... " << std::endl;
    auto m = q.front();т
    q.pop();
    lk.unlock();

    std::cout << "worker. pop " << m << std::endl;
}

int main()
{
    std::thread t1(worker, std::ref(msgs));
    
    std::this_thread::sleep_for(2s);

    {
        std::lock_guard<std::mutex> lk(cv_m);
        std::cout << "main. pushing new value to queue" << std::endl;
        msgs.push("cmd1");
    }
    cv.notify_one();

    t1.join();
    std::cout << "main. end" << std::endl;
} 

//-----------------------------------------------------------
// condition variable notify_all:

#include <chrono>
#include <condition_variable>
#include <iostream>
#include <queue>
#include <thread>

using namespace std::chrono_literals;

std::queue<std::string> msgs;
std::condition_variable cv;
std::mutex cv_m;

void worker(std::queue<std::string> &q)
{
    std::cout << "worker. started: " << std::this_thread::get_id() << std::endl;
    std::unique_lock<std::mutex> lk(cv_m);

    std::cout << "worker. before wait call" << std::endl;
    cv.wait(lk, [&q](){ std::cout << "worker. wait condition check" << std::endl; return !q.empty(); });
    std::cout << "worker. processing ... " << std::endl;
    auto m = q.front();
    q.pop();
    lk.unlock();

    std::cout << "worker. pop " << m << std::endl;
}

int main()
{
    std::thread t1(worker, std::ref(msgs));
    std::this_thread::sleep_for(1s);

    std::thread t2(worker, std::ref(msgs));
    std::this_thread::sleep_for(1s);

    {
        std::lock_guard<std::mutex> lk(cv_m);
        std::cout << "main. pushing new value to queue" << std::endl;
        msgs.push("cmd1");
        msgs.push("cmd2");
    }
    
    /*cv.notify_all(); or... */
    cv.notify_one();
    std::this_thread::sleep_for(1s);
    cv.notify_one();

    t1.join();
    t2.join();
  
  std::cout << "main. end" << std::endl;
} 

//-----------------------------------------------------------
// compile-time method call count:

#include <iostream>

template <typename T, int N>
struct result 
{
    T values[N];
};

template <typename T, int I, int N>
class builder_ 
{
    
private:    
    
    T*  values;
    
    friend class builder_<T, I - 1, N>;
    
    builder_(T* values)
        : values(values) 
        { 
            std::cout << " private ctor" << '\n'; 
        }
    
public:
    
    builder_(result<T, N>& r)
        : values(r.values) 
        { 
            std::cout << " public ctor" << '\n'; 
        }
    
    builder_<T, I + 1, N> set(T const& value) 
    {
        std::cout << " set" << '\n';
        
        *values = value;
        return builder_<T, I + 1, N>(this->values + 1);
    }
    
};

template <typename T, int N>
class builder_<T, N, N> 
{
    
public:
    
    builder_(T*) 
    { 
        std::cout << " specialized ctor" << '\n'; 
    }
    
};

template <typename T, int N>
auto builder(result<T, N>& r) 
{
    std::cout << "in function builder" << '\n';
    return builder_<T, 0, N>(r);
}

int main()
{
    std::cout << "Start program" << '\n';
    result<int, 4> r;
    builder(r)
        .set(1)
        .set(2)
        .set(3)
        .set(4)
        ;
    std::cout << "End program" << '\n';
}

//-----------------------------------------------------------
// compile-time method call count:

#include <iostream>
#include <string>

using namespace std;

template<size_t D>
class Proxy
{
public:
    Proxy<D - 1> operator[](size_t) const
    {
        return Proxy<D - 1>{};
    }
};

template<>
class Proxy<1>
{
public:
    size_t operator[](size_t) const
    {
        return 77;
    }
};

template<size_t D>
class Matrix
{
public:
    Proxy<D> operator[](size_t) const
    {
        return Proxy<D>{};
    }
};

int main()
{
    const Matrix<4> mat{};
    cout << mat[0][1][2][3][4];
}

//-----------------------------------------------------------
// tuple with given size and type:

#include <tuple>

template<typename CoordinateType, unsigned N, typename... REST>
struct generate_tuple_type
{
 typedef typename generate_tuple_type<CoordinateType, N-1, CoordinateType, REST...>::type type;
};

template<typename CoordinateType, typename... REST>
struct generate_tuple_type<CoordinateType, 0, REST...>
{
  typedef std::tuple<REST...> type;
};

int main()
{
  using gen_tuple_t = generate_tuple_type<int, 3, double>::type;
  using hand_tuple_t = std::tuple<int, int, int, double>;
  static_assert( std::is_same<gen_tuple_t, hand_tuple_t>::value, "different types" );
}

//-----------------------------------------------------------
// algorithm - quicksort:
#include <iostream>

template <class T>
void swap(T & el1, T & el2)
{
  T tmp = el1;
  el1 = el2;
  el2 = tmp;
}

template <class T>
    int partition(T A[], int low, int high)
{
    int mid = (low + high) / 2;
    T pivot = A[mid];
    
    int scanUp = low;
    int scanDown = high;

    while(scanUp <= scanDown)
    {
        while(A[scanUp] < pivot)
            scanUp++;

        while(A[scanDown] > pivot)
            scanDown--;

        if(scanUp >= scanDown)
            break;
            
        swap(A[scanUp++], A[scanDown--]);
    }
    
    return scanDown;
}

template<typename T>
void quickSort(T array[], int low, int high)
{
    if(low < high)
    {
        int q = partition(array, low, high);
        quickSort(array, low, q);
        quickSort(array, q + 1, high);
    }
    return;
}

int main()
{
    double array[] = {1, 7, 4, 8, 13.6, 25, 6, 50, 14, 3, 2, 1};
    quickSort(array, 0, 11);
    
    for (int i = 0; i < 12; i++)
        std::cout << array[i] << " ";
}

//-----------------------------------------------------------
// algorithm - bubblesort:

#include <iostream>

template<typename T>
void swap(T & el1, T & el2)
{
  T temp = el1;
  el1 = el2;
  el2 = temp;
}

template<typename T>
void bubbleSort(T array[], int size)
{
  bool swapFlag{ true };

  while (swapFlag)
  {
    swapFlag = false;

    for (int i = 0; i < size - 1; ++i)
    {
      if (array[i] > array[i + 1])
      {
        swap(array[i], array[i + 1]);
        swapFlag = true;
      }
    }
  }
}

int main()
{
  int array[] = { 1, 2, 3, 6, 8, 4, 12, 15, 5 };
  bubbleSort(array, 9);

  for (int i = 0; i < 9; ++i)
    std::cout << array[i] << " ";

  return 0;
}
