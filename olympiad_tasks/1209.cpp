// Task - http://acm.timus.ru/problem.aspx?space=1&num=1209&locale=en

#include <iostream>
#include <vector>
#include <cmath>

auto getNumbers()
{
  unsigned int numbersCount;
  std::cin >> numbersCount;
  std::cin.ignore();

  std::vector<size_t> numbers;
  numbers.reserve(numbersCount);

  size_t number;

  while (numbersCount--)
  {
    std::cin >> number;
    numbers.push_back(number);
  }

  return numbers;
}

int main()
{
    unsigned long long num;
    std::cin >> num;
    
    while(std::cin >> num)
    {
        double n = sqrt(8*num - 7);
        
        if (n == (int) n)
            std::cout << "1" << " ";
        else
            std::cout << "0" << " ";
    }
}