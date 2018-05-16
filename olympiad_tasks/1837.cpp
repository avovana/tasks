// Task - http://acm.timus.ru/problem.aspx?num=1837&locale=en

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

int main(int, char**)
{
    std::map<std::string, int> namesResult;
    std::set<std::string> contestants;
    std::set<std::vector<std::string>> teams;
    
    int num;
    std::cin >> num;
    
    while(num--)
    {
        std::vector<std::string> team;
        int iterations = 3;
        std::string name;
        
        while(iterations--)
        {
            std::cin >> name;
            team.push_back(name);
            
            if(name == "Isenbaev")
                contestants.insert(name);
        }
        
        teams.insert(team);
    }
     
    //--------------------------------------------
    
    for(int number = 0; !contestants.empty(); ++number)
    {
        decltype(contestants) teammates;
        decltype(teams) remainingTeams;
        
        for(auto& contestant : contestants)
            namesResult[contestant] = number;
        
        for(auto& team : teams)
        {
            bool foundTeammates = std::any_of(team.cbegin(), team.cend(), 
                                              [&](auto name){ return contestants.find(name) != contestants.end();});
            if (foundTeammates)
            {
                for(auto& name : team) 
                {
                    if(contestants.find(name) == contestants.end())
                        teammates.insert(name);
                }
            }
            else
            {
                remainingTeams.insert(team);
            }
        }

        teams = remainingTeams;
        
        contestants = teammates;
    }
    
    //--------------------------------------------
    
    for(auto& team : teams)
    {
        for(auto& name : team)
            namesResult[name] = - 1;
    }

    for(auto& names : namesResult)
    {
        std::cout << names.first << " ";
        if(names.second != -1)
            std::cout << names.second << '\n';
        else
            std::cout << "undefined" << '\n';
    }
    
    return 0;
}