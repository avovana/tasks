#include <iostream>
#include <cstdlib>
#include <type_traits>
#include <string>

#include "is_container.h"

using byte = unsigned char;

template <class T>
std::enable_if_t<std::is_fundamental<T>::value, void> print_ip(const T &number_)
{
	T number = number_;

	byte array[sizeof(T)];

	for (unsigned int i = 0; i < sizeof(T); ++i)
	{
		array[i] = number;
		number >>= 8;
	}

	for (unsigned int i = sizeof(T) - 1; i >= 0; --i)
	{
		std::cout << (int)array[i];

		if (i == 0)
			break;
		else
			std::cout << ".";
	}
	std::cout << std::endl;
}

template <class T>
std::enable_if_t<is_stl_container<T>::value, void> print_ip(const T &container)
{
	for (auto it = std::begin(container); it != std::end(container); ++it)
	{
		std::cout << *it;

		if (std::next(it, 1) != std::end(container))
			std::cout << "..";
	}
	std::cout << std::endl;
}

template<typename T>
struct is_string : public std::integral_constant<bool, std::is_same<char*, typename std::decay<T>::type>::value || std::is_same<const char*, typename std::decay<T>::type>::value> {};

template<>
struct is_string<std::string> : std::true_type {};

template <typename T>
typename std::enable_if<is_string<T>::value, void>::type
print_ip(T const & x)
{
	std::cout << x << std::endl;
}
