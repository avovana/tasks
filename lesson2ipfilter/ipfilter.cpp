#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include <functional>   // std::greater
#include <algorithm>    // std::sort

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d)
{
	std::vector<std::string> r;

	std::string::size_type start = 0;
	std::string::size_type stop = str.find_first_of(d);
	while (stop != std::string::npos)
	{
		r.push_back(str.substr(start, stop - start));

		start = stop + 1;
		stop = str.find_first_of(d, start);
	}

	r.push_back(str.substr(start));

	return r;
}

using ip_adress = std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>;

std::ostream& operator<<(std::ostream& os, const ip_adress& ip)
{
	os << static_cast<int>(std::get<0>(ip))
		<< "."
		<< static_cast<int>(std::get<1>(ip))
		<< "."
		<< static_cast<int>(std::get<2>(ip))
		<< "."
		<< static_cast<int>(std::get<3>(ip));

	return os;
}

ip_adress getIpAdress(const std::string &str, char d)
{
	std::vector<std::string> r;

	std::string::size_type start = 0;
	std::string::size_type stop = str.find_first_of(d);
	for(int i = 0; stop != std::string::npos; ++i)
	while (stop != std::string::npos)
	{
		r.push_back(str.substr(start, stop - start));

		start = stop + 1;
		stop = str.find_first_of(d, start);
	}
	r.push_back(str.substr(start));

	assert(r.size() == 4);

	return std::make_tuple(std::stoi(r.at(0)), std::stoi(r.at(1)), std::stoi(r.at(2)), std::stoi(r.at(3)));
}

int main(int argc, char const *argv[])
{
	try
	{
		std::vector<ip_adress> ip_pool;

		for (std::string line; std::getline(std::cin, line);)
		{
			std::vector<std::string> v = split(line, '\t');
			ip_pool.push_back(getIpAdress(v.at(0), '.'));
		}

		std::sort(ip_pool.begin(), ip_pool.end(), std::greater<ip_adress>());

		for (const auto & ip : ip_pool) {
			std::cout << ip << std::endl;
		}

		for (const auto & ip : ip_pool) {
			if (std::get<0>(ip) == 1) {
				std::cout << ip << std::endl;
			}
		}

		for (const auto & ip : ip_pool) {
			if ((std::get<0>(ip) == 46) &&
				(std::get<1>(ip) == 70)) {
				std::cout << ip << std::endl;
			}
		}

		for (const auto & ip : ip_pool) {
			if ((std::get<0>(ip) == 46) ||
				(std::get<1>(ip) == 46) || 
				(std::get<2>(ip) == 46) ||
				(std::get<3>(ip) == 46)) {
				std::cout << ip << std::endl;
			}
		}

	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
