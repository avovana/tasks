#pragma once

#include <iostream>
#include <cstdlib>
#include <type_traits>
#include <string>

#include "is_container.h"

using byte = std::uint8_t;

template <class T>
std::enable_if_t<std::is_integral<T>::value, void> print_ip(std::ostream& os, const T &number_)
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
		os << (int)array[i];

		if (i == 0)
			break;
		else
			os << ".";
	}
}

template <class T>
std::enable_if_t<is_stl_container<T>::value && std::is_integral<typename T::value_type>::value, void> print_ip(std::ostream& os, const T &container)
{
	for (auto it = std::begin(container); it != std::end(container); ++it)
	{
		os << *it;

		if (std::next(it, 1) != std::end(container))
			os << ".";
	}
}

template<typename T>
struct is_string : public std::integral_constant<bool, std::is_same<char*, typename std::decay<T>::type>::value || std::is_same<const char*, typename std::decay<T>::type>::value> {};

template<>
struct is_string<std::string> : std::true_type {};

template <typename T>
typename std::enable_if<is_string<T>::value, void>::type
print_ip(std::ostream& os, T const & x)
{
	os << x;
}
