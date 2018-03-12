// http://acm.timus.ru/problem.aspx?space=1&num=1001

//#include "stdafx.h" // for Visual Studio

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

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

int main(int argc, char const *argv[])
{
	std::vector<long long> numbers;

	for (std::string line; std::getline(std::cin, line);)
	{
		std::vector<std::string> inputNumbers = split(line);

		for (const auto &number : inputNumbers)
			numbers.push_back(std::stoll(number));
	}
	
	for (auto start = numbers.crbegin(); start != numbers.crend(); ++start) 
		std::cout << std::setprecision(4) << std::fixed << sqrt(*start) << std::endl;

	return 0;
}
