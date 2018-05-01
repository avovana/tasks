// Task - http://acm.timus.ru/problem.aspx?space=1&num=2100

#include <iostream>
#include <string>

typedef unsigned long ulong;

auto countGuests()
{
    ulong friendNum;
    std::cin >> friendNum;
    std::cin.ignore();
    
    std::string invitation;
    
    while(getline(std::cin, invitation))
    {
        auto found = invitation.find("+one");
        
        if (found != std::string::npos)
            ++friendNum;
    }

    return friendNum;
}


int main()
{
    try
    {
        ulong youngCouple = 2;
        auto guests = countGuests();
        
        auto personsOverall = guests + youngCouple;
        
        if(personsOverall == 13)
            ++personsOverall;
        
        ulong costOfServing = 100;
        
        ulong dinnerCost = personsOverall * costOfServing;
        
        std::cout << dinnerCost << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}