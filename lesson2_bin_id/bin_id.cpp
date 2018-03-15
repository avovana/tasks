#include <bits/stdc++.h>

// Реализовать constexpr функцию bin_id - определения ближайшей большей степени двойки 
namespace
{
    constexpr size_t bin_id(size_t value)
	{
        if(value <= 1)
            return 0;
        
        size_t degree = 0;
        
        if((value % 2) == 0) // есть шанс, что число - чистая степень 2ки
        {
            while((value % 2) == 0)
            {
                value = value / 2;
                ++degree;
                
                if(value == 1)
                {
                    return degree;
                }
            }
        }
        
        while(value)
        {
            value = value / 2;
            
            if(value)
                ++degree;
        }
        
		return ++degree;
	}

	static_assert(bin_id(0) == 0, "bin_id doesn't work");
	static_assert(bin_id(1) == 0, "bin_id doesn't work");
	static_assert(bin_id(2) == 1, "bin_id doesn't work");
	static_assert(bin_id(4) == 2, "bin_id doesn't work");
	static_assert(bin_id(7) == 3, "bin_id doesn't work");
	static_assert(bin_id(8) == 3, "bin_id doesn't work");
	static_assert(bin_id(9) == 4, "bin_id doesn't work");
	static_assert(bin_id(1023) == 10, "bin_id doesn't work");
	static_assert(bin_id(1024) == 10, "bin_id doesn't work");
	static_assert(bin_id(1025) == 11, "bin_id doesn't work");
	static_assert(bin_id(1024*1024-33) == 20, "bin_id doesn't work");
	static_assert(bin_id(1024*1024) == 20, "bin_id doesn't work");
	static_assert(bin_id(1024*1024+33) == 21, "bin_id doesn't work");
	static_assert(bin_id(1024*1024*1024-127) == 30, "bin_id doesn't work");
	static_assert(bin_id(1024*1024*1024) == 30, "bin_id doesn't work");
	static_assert(bin_id(1024*1024*1024+127) == 31, "bin_id doesn't work"); 
}

int main()
{
    size_t n;
    while(std::cin >> n)
        std::cout << bin_id(n) << std::endl;
    return 0;
}