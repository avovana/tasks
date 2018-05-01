// Task - http://acm.timus.ru/problem.aspx?space=1&num=2023&locale=en

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

using casePos = size_t;

std::map<std::string, casePos> sections = {
    {"Alice", 0}, {"Ariel", 0}, {"Aurora", 0}, {"Phil", 0}, {"Peter", 0}, {"Olaf", 0}, {"Phoebus", 0}, {"Ralph", 0}, {"Robin", 0},
    {"Bambi", 1}, {"Belle", 1}, {"Bolt", 1}, {"Mulan", 1}, {"Mowgli", 1}, {"Mickey", 1}, {"Silver", 1}, {"Simba", 1}, {"Stitch", 1},
    {"Dumbo", 2}, {"Genie", 2}, {"Jiminy", 2}, {"Kuzko", 2}, {"Kida", 2}, {"Kenai", 2}, {"Tarzan", 2}, {"Tiana", 2}, {"Winnie", 2}
                                       };

using lettersBag = std::vector<std::string>;

auto receiveLetters()
{
    size_t lettersNum;
    std::cin >> lettersNum;
    std::cin.ignore();
    
    lettersBag bag;
    bag.reserve(lettersNum);
    
    std::string letter;
    
    while(getline(std::cin, letter))
        bag.push_back(letter);
    
    if(lettersNum != bag.size())
        throw std::invalid_argument("Input letters number is not correct!");
    
    return bag;
}

auto findProperCasePos(const std::string& letter)
{
    auto section = sections.find(letter);
    if(section == sections.end())
        throw std::invalid_argument("Invalid recepient name");
    
    return section->second;
}

template< typename T >
T absdiff( const T& lhs, const T& rhs ) 
{
    return lhs > rhs ? lhs - rhs : rhs - lhs;
}

int main()
{
    try
    {
        size_t steps = 0;
        casePos currentPos = 0;
        
        auto bag = receiveLetters();
    
        for(const auto& letter : bag)
        {
            auto destPos = findProperCasePos(letter);
            steps = steps + absdiff(currentPos, destPos);
            
            currentPos = destPos;
        }
        
        std::cout << steps << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}