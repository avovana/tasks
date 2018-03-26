// Task - http://acm.timus.ru/problem.aspx?space=1&num=1785

#include <iostream>
#include <string>

std::string getWord(long long number)
{
	std::string word;

	if (1 <= number && number <= 4)
		word.assign("few");
	else if (5 <= number && number <= 9)
		word.assign("several");
	else if (10 <= number && number <= 19)
		word.assign("pack");
	else if (20 <= number && number <= 49)
		word.assign("lots");
	else if (50 <= number && number <= 99)
		word.assign("horde");
	else if (100 <= number && number <= 249)
		word.assign("throng");
	else if (250 <= number && number <= 499)
		word.assign("swarm");
	else if (500 <= number && number <= 999)
		word.assign("zounds");
	else if(1000 <= number)
		word.assign("legion");
	else
		throw std::invalid_argument("received negative value");

	return word;
}

int main(int argc, char const *argv[])
{
	try
	{
		long long number;
		std::cin >> number;

		auto word = getWord(number);
		std::cout << word << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
