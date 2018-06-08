// Task - http://acm.timus.ru/problem.aspx?space=1&num=1607&locale=en

#include <iostream>

int main()
{
    int offer = 0;
    int raise = 0;
    int fare  = 0;
    int reduction = 0;
    
    std::cin >> offer >> raise >> reduction >> fare;
    
    if(offer >= reduction)
    {
        std::cout << offer << std::endl;
    }
    else
    {
        while(offer < reduction)
        {
            if(offer + raise <= reduction)
                offer += raise;
            else
                offer = reduction;
                
            reduction -= fare;
        }
        std::cout << offer << std::endl;
    }
}
