// Task - http://acm.timus.ru/problem.aspx?space=1&num=1000&locale=en

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

int main(int argc, char const *argv[])
{
	std::string line;

	getline(std::cin, line);
	
	std::vector<std::string> inputNumbers = split(line);

	std::vector<long long> numbers;

	for (const auto &number : inputNumbers)
		numbers.push_back(std::stoll(number));
	
	auto sum = std::accumulate(std::begin(numbers), std::end(numbers), 0);

	std::cout << sum << std::endl;

	return 0;
}
