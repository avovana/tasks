#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include <functional>   // std::greater
#include <algorithm>    // std::sort
#include <chrono>  // for high_resolution_clock

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

	if(r.size() != 4)
		throw std::invalid_argument("wrong ip adress format!");

	return std::make_tuple(std::stoi(r.at(0)), std::stoi(r.at(1)), std::stoi(r.at(2)), std::stoi(r.at(3)));
}

int main(int argc, char const *argv[])
{
	try
	{
                  auto startProgramm = std::chrono::high_resolution_clock::now();
		std::vector<ip_adress> ip_pool;

                  auto startPush = std::chrono::high_resolution_clock::now();

		for (std::string line; std::getline(std::cin, line);)
		{
			std::vector<std::string> v = split(line, '\t');
			ip_pool.push_back(getIpAdress(v.at(0), '.'));
		}
                  auto finishPush = std::chrono::high_resolution_clock::now();
                  std::chrono::duration<double> elapsedPush = finishPush - startPush;

                  auto startSort = std::chrono::high_resolution_clock::now();
		std::sort(ip_pool.begin(), ip_pool.end(), std::greater<ip_adress>());
                  auto finishSort = std::chrono::high_resolution_clock::now();
                  std::chrono::duration<double> elapsedSort = finishSort - startSort;

                  auto startOut = std::chrono::high_resolution_clock::now();
		for (const auto & ip : ip_pool) {
			std::cout << ip << std::endl;
		}
                  auto finishOut = std::chrono::high_resolution_clock::now();
                  std::chrono::duration<double> elapsedOut = finishOut - startOut;

                  auto start_1_filtr = std::chrono::high_resolution_clock::now();
		for (const auto & ip : ip_pool) {
			if (std::get<0>(ip) == 1) {
				std::cout << ip << std::endl;
			}
		}
                  auto finish_1_filtr = std::chrono::high_resolution_clock::now();
                  std::chrono::duration<double> elapsed_1_filtr = finish_1_filtr - start_1_filtr;

                  auto start_46_70_filtr = std::chrono::high_resolution_clock::now();
		for (const auto & ip : ip_pool) {
			if ((std::get<0>(ip) == 46) &&
				(std::get<1>(ip) == 70)) {
				std::cout << ip << std::endl;
			}
		}
                  auto finish_46_70_filtr = std::chrono::high_resolution_clock::now();
                  std::chrono::duration<double> elapsed_46_70_filtr = finish_46_70_filtr - start_46_70_filtr;

                  auto start_46_any_filtr = std::chrono::high_resolution_clock::now();
		for (const auto & ip : ip_pool) {
			if ((std::get<0>(ip) == 46) ||
				(std::get<1>(ip) == 46) || 
				(std::get<2>(ip) == 46) ||
				(std::get<3>(ip) == 46)) {
				std::cout << ip << std::endl;
			}
		}
                  auto finish_46_any_filtr = std::chrono::high_resolution_clock::now();
                  std::chrono::duration<double> elapsed_46_any_filtr = finish_46_any_filtr - start_46_any_filtr;

		auto finishProgramm = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsedProgramm = finishProgramm - startProgramm;
		std::cout << "Elapsed time program:       " << elapsedProgramm.count() << " s\n" << std::endl;
		std::cout << "Elapsed time read input:    " << elapsedPush.count() << " s\n";
		std::cout << "Elapsed time out:           " << elapsedOut.count() << " s\n";
		std::cout << "Elapsed time _1_filtr:      " << elapsed_1_filtr.count() << " s\n";
		std::cout << "Elapsed time _46_70_filtr:  " << elapsed_46_70_filtr.count() << " s\n";
		std::cout << "Elapsed time _46_any_filtr: " << elapsed_46_any_filtr.count() << " s\n";
		std::cout << "Elapsed time sort:          " << elapsedSort.count() << " s\n" << std::endl;

		std::cout << "Elapsed sum of all parts:   "
				<< elapsedPush.count() +
					elapsedOut.count() +
					elapsed_1_filtr.count() +
					elapsed_46_70_filtr.count() +
					elapsed_46_any_filtr.count() << " s\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
