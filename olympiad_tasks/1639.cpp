//Task - http://acm.timus.ru/problem.aspx?space=1&num=1639

#include <iostream>
#include <cstdlib>
#include <string>

int main()
{
    size_t n;
    size_t m;
    
    std::cin >> n;
    std::cin >> m;
        
    size_t chocolateSquare = m * n;
    
    bool isEvenQuantity = chocolateSquare % 2 == 0 ? true : false;
    
    bool shouldMoveFirst = isEvenQuantity ? true : false;
    
    std::string answer = shouldMoveFirst ? "[:=[first]" : "[second]=:]";
    
    std::cout << answer << std::endl;
}

