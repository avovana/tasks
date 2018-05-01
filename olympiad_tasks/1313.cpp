// Task - http://acm.timus.ru/problem.aspx?space=1&num=1313&locale=en

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <limits>

using Raw = std::vector<unsigned int>;

struct Node
{
    size_t index{0};
    Raw raw;
};

using Matrix = std::vector<Node>;

auto getMatrix()
{
    size_t matrixDim;
    std::cin >> matrixDim;
    std::cin.ignore();
    
    Matrix matrix;
    matrix.reserve(matrixDim);
    
    unsigned int pixel;
    Raw currentRaw;
    currentRaw.reserve(matrixDim);
    
    auto raws = matrixDim;
    while(raws--)
    {
        for(auto elements = matrixDim; elements; --elements)
        {
            std::cin >> pixel;
            currentRaw.push_back(pixel);
        }
        matrix.push_back({0, currentRaw});
        currentRaw.clear();
    }
    
    return matrix;
}

auto getSequence(Matrix& matrix)
{
    Raw sequence;
    sequence.reserve(matrix.size() * matrix.size());
    
    for(size_t i = 0; i < matrix.size(); ++i)
    {
        for(size_t j = i; j != std::numeric_limits<std::size_t>::max(); --j)
        {
            auto curr = matrix[j].index;
            
            if(curr < matrix[j].raw.size())
            {
                sequence.push_back(matrix[j].raw[curr]);
                matrix[j].index++;
            }
        }
    }
    
    auto lastRaw = matrix[matrix.size() - 1];
    for(size_t i = lastRaw.index; i < lastRaw.raw.size(); ++i)
    {
        for(size_t j = matrix.size() - 1; j != std::numeric_limits<std::size_t>::max(); --j)
        {
            auto curr = matrix[j].index;
            
            if(curr < matrix[j].raw.size())
            {
                sequence.push_back(matrix[j].raw[curr]);
                matrix[j].index++;
            }
        }        
    }
    
    return sequence;
}

int main()
{
    try
    {
        auto matrix = getMatrix();
        auto sequence = getSequence(matrix);
        
        for(const auto& el : sequence)
            std::cout << el << " ";
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}