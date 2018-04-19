// Task - http://acm.timus.ru/problem.aspx?space=1&num=1877&locale=en

#include <iostream>
#include <cstdlib>

struct Code {
    size_t code{0};
    bool isHackable{true};
};

int main()
{
    Code firstCode;
    Code secondCode;

    std::cin >> firstCode.code;
    std::cin >> secondCode.code;

    firstCode.isHackable = (firstCode.code % 2 == 0) ? true : false;
    secondCode.isHackable = (secondCode.code % 2 != 0) ? true : false;
    
    bool isGuardHackable = (firstCode.isHackable || secondCode.isHackable) ? true : false;
    
    std::string result = isGuardHackable ? "yes" : "no";
    
    std::cout << result;
}