// Task - http://acm.timus.ru/problem.aspx?space=1&num=2066&locale=en

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main()
{
    int a;
    int b;
    int c;
    
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    
    std::vector<int> result;
    result.reserve(9);
    
    result.push_back(a * b * c);
    result.push_back(a * b + c);
    result.push_back(a * b - c);
    
    result.push_back(a + b * c);
    result.push_back(a + b + c);
    result.push_back(a + b - c);
    
    result.push_back(a - b * c);
    result.push_back(a - b + c);
    result.push_back(a - b - c);

    std::cout << *min_element(result.begin(), result.end()) << std::endl;                     
}