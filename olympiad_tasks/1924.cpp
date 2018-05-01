// Task - http://acm.timus.ru/problem.aspx?space=1&num=1924

#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;
    
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += i;
    }
      
    if(sum % 2 == 0)
        std::cout << "black";
    else
        std::cout << "grimy";

    return 0;
}