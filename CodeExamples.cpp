//-----------------------------------------------------------
//std::map. default value

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
// Get the type name in C++14 at compile time
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