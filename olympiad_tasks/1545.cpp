// Task - http://acm.timus.ru/problem.aspx?num=1545&locale=en

#include <iostream>
#include <map>
#include <utility>

int main(int, char**)
{
    int num{};
    
    std::cin >> num;
    
    std::multimap<char, char> hieroglyphs;
    
    while(num--)
    {
        char symbol1;
        char symbol2;
        std::cin >> symbol1 >> symbol2;
        hieroglyphs.insert ( std::make_pair(symbol1, symbol2) );
    }
    
    char symbol;
    std::cin >> symbol;

    auto range = hieroglyphs.equal_range(symbol);
    for(auto begin = range.first; begin != range.second; begin++)
    {
        std::cout << begin->first << begin->second << '\n';
    }
    
    return 0;
}