// Task - http://acm.timus.ru/problem.aspx?space=1&num=1327

#include <iostream>

int main(int, char* [])
{
    int firstDay{0};
    int secondDay{0};
    
    std::cin >> firstDay >> secondDay;

    bool isOdd = (firstDay % 2) || (secondDay % 2);

    std::cout << ((secondDay - firstDay) / 2 + isOdd);

    return 0;
}