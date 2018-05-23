// Task - http://acm.timus.ru/problem.aspx?space=1&num=1876&locale=en

#include <iostream>
#include <vector>
#include <numeric>

int main(int, char **)
{
    unsigned char symbol;
    std::vector<int> numbers;
    numbers.reserve(6);
    
    while(std::cin >> symbol)
    {
        auto number = symbol - 48;
        numbers.push_back(number);
    }
    
    int firstPart = std::accumulate(std::begin(numbers), std::begin(numbers) + 3, 0);
    int secondPart = std::accumulate(std::begin(numbers) + 3, std::end(numbers),  0);
    int lastDigit = numbers.back();
    
    bool isNextLuckyTicket = (firstPart == secondPart + 1) && (lastDigit != 9);
    bool isPrevLuckyTicket = (firstPart == secondPart - 1) && (lastDigit != 0);
    
    auto answer = isNextLuckyTicket || isPrevLuckyTicket ? "Yes" : "No";
    
    std::cout << answer;
    
    return 0;
}