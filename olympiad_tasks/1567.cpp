// Task - http://acm.timus.ru/problem.aspx?space=1&num=1567

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <algorithm>
#include <map>

int main()
{
    char symbol;
    int sum = 0;
    
    std::vector<int> letterWeights(26);
    std::map<char, int> signWeights{{'.', 1}, {',', 2}, {'!', 3}, {' ', 1}};
    
    
    int num = 0;
    std::generate_n (letterWeights.begin(), letterWeights.size(), 
                     [&num]()
                     {
                         ++num;
                         return num % 3 ? num % 3 : 3 ;
                     });
    
    size_t summ = 0;
    
    while(std::cin >> std::noskipws >> symbol)
    {
        if(std::isalpha(symbol))
        {
            int number = symbol - 'a';
            summ += letterWeights[number];
        }           
        else
        {
            summ += signWeights[symbol];
        }
    }
    
    std::cout << summ;
}