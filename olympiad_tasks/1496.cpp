// Task - http://acm.timus.ru/problem.aspx?num=1496&locale=en

#include <iostream>
#include <string>
#include <set>

int main(int, char**)
{
    std::set<std::string> submitted;
    std::set<std::string> spammers;

    int num{};
    std::cin >> num;

    std::string team;

    while(num--)
    {
        std::cin >> team;
        auto res = submitted.insert(team);

        if(res.second == false)
            spammers.insert(team);
    }

    for(auto el : spammers)
    {
        std::cout << el << '\n';
    }

    return 0;
}