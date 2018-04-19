// Task - http://acm.timus.ru/problem.aspx?space=1&num=1787&locale=en

#include <iostream>

int main()
{
    size_t carsBandwidth;
    std::cin >> carsBandwidth;
    
    size_t minutesObserved;
    std::cin >> minutesObserved;
    
    size_t carsInTrafficJam = 0;
    
    for(size_t carsPulledUp; std::cin >> carsPulledUp;)    
    {
        if(carsPulledUp >= carsBandwidth)
        {
            size_t carsWait = carsPulledUp - carsBandwidth;
            carsInTrafficJam += carsWait;
        } 
        else 
        {
            size_t carsCanGo = carsBandwidth - carsPulledUp;
            
            if(carsInTrafficJam >= carsCanGo)
                carsInTrafficJam -= carsCanGo;
            else
                carsInTrafficJam = 0;
        }
    }
    
    std::cout << carsInTrafficJam;
}