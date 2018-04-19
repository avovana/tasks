// Task - http://acm.timus.ru/problem.aspx?space=1&num=1197&locale=en

#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <string>

auto getPositions()
{
  std::string line;
  std::vector<std::pair<size_t, size_t>> positions;

  while (getline(std::cin, line))
  {
    size_t horizontalValue = line.at(0) - 'a' + 1;
    size_t verticalValue = line.at(1) - '0';

    auto pos = std::make_pair(horizontalValue, verticalValue);
    positions.push_back(pos);
  }

  return positions;
}

auto tryToMove(size_t pos1, size_t pos2)
{
  const int cellsLimit = 8;
  size_t steps = 0;

  if (pos1 + 2 <= cellsLimit)
  {
    if (pos2 + 1 <= cellsLimit)
    {
      ++steps;
    }
    if (pos2 >= 2)
    {
      ++steps;
    }
  }

  if (pos1 >= 3)
  {
    if (pos2 + 1 <= cellsLimit)
    {
      ++steps;
    }
    if (pos2 >= 2)
    {
      ++steps;
    }
  }

  return steps;
}

auto availableSteps(const std::pair<size_t, size_t>& pos)
{
  size_t steps = 0;

  steps += tryToMove(pos.first, pos.second);
  steps += tryToMove(pos.second, pos.first);

  return steps;
}

int main()
{
  size_t testNumbers = 0;
  std::cin >> testNumbers;
  std::cin.ignore();

  auto startPositions = getPositions();

  for (auto const& pos : startPositions)
    std::cout << availableSteps(pos) << std::endl;
}