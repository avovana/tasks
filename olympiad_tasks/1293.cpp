// http://acm.timus.ru/problem.aspx?space=1&num=1293

// #include "stdafx.h" // for Visual Studio

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

std::vector<std::string> split(const std::string &str)
{
	std::string::size_type start = str.find_first_not_of(" ");
	std::string::size_type stop = 0;

	std::vector<std::string> r;

	while (start != std::string::npos)
	{
		stop = str.find_first_of(" ", start);
		r.push_back(str.substr(start, stop - start));

		start = str.find_first_not_of(" ", stop);
	}

	return r;
}

void checkRange(const std::vector<long long>& numbers)
{
	if(numbers.size() != 3)
		throw std::invalid_argument("received not 3 values");
	if(!(1 <= numbers.at(0)) || !(numbers.at(0) <= 100) ||
	   !(1 <= numbers.at(1)) || !(numbers.at(1) <= 100) ||
	   !(1 <= numbers.at(2)) || !(numbers.at(2) <= 100))
		throw std::invalid_argument("received values not within a valid range");
}

int main(int argc, char const *argv[])
{
	try
	{
		std::string line;
		std::getline(std::cin, line);
		std::vector<std::string> inputNumbers = split(line);

		std::vector<long long> numbers;

		for (const auto &number : inputNumbers)
			numbers.push_back(std::stoll(number));

		checkRange(numbers);

		auto product = std::accumulate(std::begin(numbers), std::end(numbers), 2, std::multiplies<decltype(numbers)::value_type>());
		std::cout << product << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}