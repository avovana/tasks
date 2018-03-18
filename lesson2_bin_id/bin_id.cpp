#include <bits/stdc++.h>

// Реализовать constexpr функцию bin_id - определения ближайшей большей степени двойки 
namespace
{
    constexpr size_t bin_id(size_t value)
	{
		size_t degree = 0;
		bool pure_power = true;
	
		while (n) 
		{
			if (n != 0b1)					// Число еще не выродилось в 1ый бит?
				if ((n & 0b1) == 0b1)		// Проверяем, есть ли 1ый бит
					pure_power = false;		// Значит есть еще как минимум какой-нибудь бит
	
			n >>= 1;
	
			if (n)
				++degree;
		}
	
		if (pure_power)
			return degree;
		else
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