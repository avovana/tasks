// Task - http://acm.timus.ru/problem.aspx?space=1&num=1991

#include <iostream>

int main()
{
    int blocks;
    int droids;
    
    std::cin >> blocks;
    std::cin >> droids;
    
    int unusedBooms = 0;
    int survivedDroids = 0;
    
    int boomBooms = 0;
    while(std::cin >> boomBooms)
    {
        if(boomBooms >= droids)
        {
            unusedBooms += ( boomBooms - droids);
        }
        else
        {
            survivedDroids += droids - boomBooms;
        }
    }    
    
    std::cout << unusedBooms << " " << survivedDroids << std::endl;
    
    return 0;
}