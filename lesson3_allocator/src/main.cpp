// forward_list example + rebind + refactoring + standart allocator/custom allocator + input size for allocation with template parametr + map

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

#include "allocatorarena.h"
#include "forward_list.h"

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main()
{
    std::map<int, int> map1;
    std::map<int, int, std::less<int>, ArenaAllocator<std::pair<const int, int>, 400>> map2;
    
    for(size_t i = 0; i < 10; ++i)
    {
        map1[i] = factorial(i);
        map2[i] = factorial(i);
    }
    
    for(auto& p : map1)
    {
        std::cout << p.first << " " << p.second << '\n';
    }
    
    for(auto& p : map2)
    {
        std::cout << p.first << " " << p.second << '\n';
    }    
    
	ForwardList<int, ArenaAllocator<int, 200>> list;
    ForwardList<int> list2;
    for(size_t i = 0; i < 10; ++i)
    {
        list.append(i);
        list2.append(i);
    }
    
	list.display();
    list2.display();
}
