#include <bits/stdc++.h>

// Реализовать constexpr функцию bin_id - определения ближайшей большей степени двойки 
namespace
{
	#define b_01 1

	constexpr bool additionalBitsAbsent(size_t value)
	{
		return (value != b_01) ? (
								  ((value & b_01) != b_01) ? true : false
								 )
								 : true;
	}

	constexpr size_t bin_id(size_t val, bool pure_power = true, size_t degree = 0)
	{
		return val ? (
					  (val >> 1) ?															
								   pure_power ? 
											    degree + 1 + bin_id(val >> 1, additionalBitsAbsent(val))
											  : degree + 1 + bin_id(val >> 1, false)
								 : pure_power ? 0 : 1
					 )
					 : 0;
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