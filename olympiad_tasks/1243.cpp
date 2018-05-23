// Task - http://acm.timus.ru/problem.aspx?space=1&num=1243&locale=en

#include <iostream>
#include <string>

int main(int, char **)
{
    std::string str;

    std::cin >> str;

    size_t reminder = str.at(0) - '0';
    for (size_t i = 0; i < str.size() - 1; ++i)
    {
        size_t nextDigit = str.at(i + 1) - '0';

        size_t num = reminder * 10 + nextDigit;

        size_t multiplier = 0;
        while (multiplier * 7 < num)
        {
            if ((multiplier + 1) * 7 > num)
                break;
            else
                ++multiplier;
        }

        reminder = num - multiplier * 7;
    }
    
    std::cout << reminder % 7;
}