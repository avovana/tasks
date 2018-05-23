// Task - http://acm.timus.ru/problem.aspx?space=1&num=1876&locale=en

#include <iostream>

int main(int, char **)
{
    int leftSlippers{0};
    int rightSlippers{0};
    
    std::cin >> leftSlippers >> rightSlippers;
    
    if(leftSlippers > rightSlippers)
    {
        int sum{0};

        rightSlippers -= 39;
        sum += 39 * 2;

        leftSlippers -= 40;
        sum += 40;

        sum += leftSlippers * 2;
        sum += 1;

        std::cout << sum;
    }
    else
    {
        int sum{0};

        sum += rightSlippers * 2;

        sum += 40;

        std::cout << sum;
    }
    
    return 0;
}