// Task - http://acm.timus.ru/problem.aspx?space=1&num=1263

#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    int candidates;
    int electors;
    
    std::cin >> candidates;
    std::cin >> electors;
    
    std::vector<int> candidatesVotes(candidates);
    
    int candidateVote = 0;
    while(std::cin >> candidateVote)
    {
        candidatesVotes[candidateVote - 1]++;
    }    
    
    for(const auto& votes : candidatesVotes)
    {
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        
        double voteRatio =( (double)votes / electors ) * 100;
        
        std::cout << voteRatio << "%" << std::endl;
    }
    
    return 0;
}