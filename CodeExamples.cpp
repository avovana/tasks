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