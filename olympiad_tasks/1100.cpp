// Task - http://acm.timus.ru/problem.aspx?space=1&num=1100

#include <iostream>
#include <cstdint>
#include <vector>
#include <utility>
#include <algorithm>

using solvedTasks = std::uint8_t;
using id = std::uint32_t;
using team = std::pair<id, solvedTasks>;

int main()
{
    size_t n;
    std::cin >> n;
    
    std::vector<team> teams;
    teams.reserve(n);
    
    solvedTasks currSolved;
    id currId;
    
    while(n--)
    {
        std::cin >> currId;
        std::cin >> currSolved;
        teams.push_back({currId, currSolved});
    }
    
    std::stable_sort(teams.begin(), teams.end(), [](auto a, auto b) {
        return a.second > b.second;   
    });
    
    for(const auto& team : teams)
    {
        std::cout << team.first << " " << team.second  << std::endl;
    }

    return 0;
}