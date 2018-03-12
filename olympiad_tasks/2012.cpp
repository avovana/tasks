// http://acm.timus.ru/problem.aspx?space=1&num=2012

// #include "stdafx.h" // for Visual Studio

#include <iostream>
#include <string>
#include <chrono>

using namespace std::chrono_literals;

auto availableTime = 4h;
auto timeForOneTask = 45min;

constexpr int canBeSolvedTasks()
{
	return availableTime / timeForOneTask;
}

void checkRange(int number)
{
	if (!(1 <= number) || !(number <= 11))
		throw std::invalid_argument("received value not within a valid range");
}

int main(int argc, char const *argv[])
{
	try
	{
		int solvedTasks;
		std::cin >> solvedTasks;
		checkRange(solvedTasks);

		int overallTasks = 12;

		if(solvedTasks + canBeSolvedTasks() >= overallTasks)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}