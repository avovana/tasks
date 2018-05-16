// Task - http://acm.timus.ru/problem.aspx?num=1196&locale=en

#include <iostream>
#include <set>

int main(int, char**)
{
    std::set<int> teachersList;
    int count{};
    
    int num{};
    std::cin >> num;

    int data{};
    while(num--)
    {
        std::cin >> data;
        teachersList.insert(data);
    }
    
    std::cin >> num;
    while(num--)
    {
        std::cin >> data;
        auto res = teachersList.find(data);
        
        if(res != teachersList.end())
        {
            ++count;
        }
    }
    
    std::cout << count << '\n';

    return 0;
}