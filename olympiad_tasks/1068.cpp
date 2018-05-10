// Task - http://acm.timus.ru/problem.aspx?space=1&num=1068&locale=en
// work + sum of progression + check 0

#include <iostream>
 
int main()
{
    long num;
    std::cin >> num;

    long size;

    if(num < 0)
    {
        size = ((1 + num) * (std::abs(num) + 2) ) / 2;
    }
    else if(num == 0)
    {
        size = 1;
    }
    else
    {
        size = ((1 + num) * num) / 2;
    }

    std::cout << size;     
}