// Task - http://acm.timus.ru/problem.aspx?space=1&num=1409&locale=en

#include <iostream>
#include <cstdlib>

int main()
{
    size_t gariesCans = 0;
    size_t lariesCans = 0;
    
    std::cin >> gariesCans;
    std::cin >> lariesCans;
    
    size_t bothCans = gariesCans + lariesCans;
    size_t sharedCans = 1;
    
    size_t gariesCansLeft = bothCans - sharedCans - gariesCans;
    size_t lariesCansLeft = bothCans - sharedCans - lariesCans;
    
    std::cout << gariesCansLeft << " " << lariesCansLeft << std::endl;
}