#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include <functional>   // std::greater
#include <algorithm>    // std::sort

#include "lib.cpp"
#include "filter_func.cpp"

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

void print(const ip_adress& ip)
{
  printf("%d.%d.%d.%d\n",
    static_cast<int>(std::get<0>(ip)),
    static_cast<int>(std::get<1>(ip)),
    static_cast<int>(std::get<2>(ip)),
    static_cast<int>(std::get<3>(ip)));
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

		std::sort(std::begin(ip_pool), std::end(ip_pool), std::greater<ip_adress>());

		for (const auto & ip : ip_pool) {
			print(ip);
		}

                //for (const auto & ip : ip_pool) {
                //	if (std::get<0>(ip) == 1) {
                //		print(ip);
                //	}
                //}

                std::vector<ip_adress> filtered = ipFilter(ip_pool, FILTER_MATCH::IN_ORDER, 1);
                std::cout << "Output 1: -------------------------" << std::endl;
                for (const auto & ip : filtered)
                    print(ip);

		for (const auto & ip : ip_pool) {
			if ((std::get<0>(ip) == 46) &&
				(std::get<1>(ip) == 70)) {
				print(ip);
			}
		}

		for (const auto & ip : ip_pool) {
			if ((std::get<0>(ip) == 46) ||
				(std::get<1>(ip) == 46) || 
				(std::get<2>(ip) == 46) ||
				(std::get<3>(ip) == 46)) {
				print(ip);
			}
		}

	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
