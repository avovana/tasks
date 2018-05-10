// Task - http://acm.timus.ru/problem.aspx?space=1&num=1581&locale=en

#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;
    
    int prevNum = 0;
    std::cin >> prevNum;
    int count = 1;
    
    int newNum = 0;
    
    while(std::cin >> newNum)
    {
        if(prevNum == newNum)
        {
            ++count;
        }
        else
        {
            std::cout << count << " " << prevNum << " ";
            count = 1;
            prevNum = newNum;
        }
    }
    
    std::cout << count << " " << prevNum << " ";
 
    return 0;
}