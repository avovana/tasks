// Task - http://acm.timus.ru/problem.aspx?space=1&num=1585

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using penguinId = int;
std::map<std::string, penguinId> penguinsTypes{{"Emperor Penguin", 0}, {"Macaroni Penguin", 1}, {"Little Penguin", 2}};

int main()
{
    int n = 0;
    std::cin >> n;
    std::cin.ignore();
    
    std::string penguin;
    std::vector<penguinId> penguins(penguinsTypes.size());
    
    while(std::getline(std::cin, penguin))
    {
        auto penguinId = penguinsTypes[penguin];
        penguins[penguinId]++;
    }
    
    auto largestPenguinsId = std::max_element(std::begin(penguins), std::end(penguins)) - std::begin(penguins);
    
    for(const auto& penguinsType : penguinsTypes)
    {
        if(penguinsType.second == largestPenguinsId)
        {
            std::cout << penguinsType.first;
            break;
        }
    }
    
    return 0;
}