// Task - http://acm.timus.ru/problem.aspx?space=1&num=1319

#include <iostream>
#include <cstdlib>
#include <list>
#include <algorithm>

int main()
{
    int size = 0;
    std::cin >> size;
    
    int diagonals = 2 * size - 1;
    int mainDiagonal = size;

    for(int raw = 1; raw <= size; ++raw)
    {
        for(int col = size; col > 0; --col)
        {
            int diagonal = col + raw - 1;
            
            if(diagonal <= mainDiagonal)
            {
                int n = diagonal - 1;
                int triangleNum = (n * (n + 1)) / 2;
                
                int num = triangleNum + raw;
                
                std::cout << num << " ";
            }
            else
            {
                int n = diagonals - diagonal;
                int triangleNum = (n * (n + 1)) / 2;
                
                int num = size * size - triangleNum - (size - raw);
                
                std::cout << num << " ";
                
            }
        }
        std::cout << std::endl;
    }
    
}
