// Task - http://acm.timus.ru/problem.aspx?space=1&num=1820&locale=en

#include <iostream>
#include <vector>
#include <algorithm>

enum class StakeState { FRESH, JUST_HALF_FRIED, HALF_FRIED, FRIED };

int main()
{
    size_t steaks;
    std::cin >> steaks;
    
    std::vector<StakeState> operationsToFryStakes(steaks, StakeState::FRESH);
    
    size_t panLimitOperations;
    std::cin >> panLimitOperations;
    
    size_t operationNumbers = 0;
    
    while (!std::all_of(operationsToFryStakes.cbegin(), operationsToFryStakes.cend(), [](auto state){ return state == StakeState::FRIED; }) )
    {
        size_t limit = panLimitOperations;
        
        while(limit)
        {
            auto result = std::find(std::begin(operationsToFryStakes), std::end(operationsToFryStakes), StakeState::FRESH);
            
            if (result != std::end(operationsToFryStakes))
            {
                *result = StakeState::JUST_HALF_FRIED;
                --limit;
            }
            else
            {
                break;
            }
        }
        
        while(limit)
        {
            auto doesNeedFries = [](auto state) 
                { 
                    if(state == StakeState::HALF_FRIED) 
                        return true;
                    else
                        return false;
                };
            
            auto result2 = std::find_if(operationsToFryStakes.begin(), operationsToFryStakes.end(), doesNeedFries);
            
            if (result2 != std::end(operationsToFryStakes))
            {
                *result2 = StakeState::FRIED;
                --limit;
            }
            else
            {
                break;
            }
        }
        
        auto turnToHalfFryState = [](auto state) 
                { 
                    if(state == StakeState::JUST_HALF_FRIED) 
                        return StakeState::HALF_FRIED;
                    else
                        return state;
                };
        
        std::transform (operationsToFryStakes.begin(), operationsToFryStakes.end(), operationsToFryStakes.begin(), turnToHalfFryState);
        
        ++operationNumbers;
  
    }
    
    std::cout << operationNumbers << std::endl;
}

/*
int main()
{
    size_t steaks;
    std::cin >> steaks;
    
    size_t friesLimit;
    std::cin >> friesLimit;
    
    size_t friesNeeded = steaks * 2;

    std::cout << friesNeeded / friesLimit;
}
*/

/*
int main()
{
    size_t steaks;
    std::cin >> steaks;
    
    size_t halfSteaksLeft = steaks * 2;
    
    size_t friesLimit;
    std::cin >> friesLimit;
    
    size_t operations = 0;
    
    while(halfSteaksLeft)
    {
        ++operations;
        if(halfSteaksLeft > friesLimit)
            halfSteaksLeft -= friesLimit;    
        else
            halfSteaksLeft = 0;
    }
    
    std::cout << operations;
}
*/