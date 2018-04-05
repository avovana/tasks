// Task - http://acm.timus.ru/problem.aspx?space=1&num=1910&locale=en

#include <iostream>
#include <cstdlib>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>

struct Entry
{
  size_t totalPower;
  size_t middleSection;
};

std::ostream& operator<<(std::ostream& os, const Entry& entry)
{
  os << entry.totalPower << " " << entry.middleSection;
  return os;
}

auto readInput()
{
  size_t sectionsNum = 0;

  std::cin >> sectionsNum;

  if (sectionsNum == 0)
    throw std::invalid_argument("Error: 0 sections!");

  std::vector<size_t> magicPowerPerSection;

  size_t power = 0;
  while (sectionsNum--)
  {
    std::cin >> power;
    magicPowerPerSection.push_back(power);
  }

  return magicPowerPerSection;
}

auto searchEntry(std::vector<size_t> magicPowersPerSection)
{
  const size_t sectionsToCheck = 3;
  size_t sumOfPowersPrev = 0;
  size_t middleSectionOfMaxSum = 0;

  for (size_t currentSection = 0; currentSection + sectionsToCheck <= magicPowersPerSection.size(); ++currentSection)
  {
    size_t sumOfPowersNew = std::accumulate(magicPowersPerSection.begin() + currentSection,
      magicPowersPerSection.begin() + currentSection + sectionsToCheck,
      size_t(0)
    );

    if (sumOfPowersNew > sumOfPowersPrev)
    {
      sumOfPowersPrev = sumOfPowersNew;
      middleSectionOfMaxSum = currentSection + 2;
    }
  }

  return Entry{ sumOfPowersPrev, middleSectionOfMaxSum };
}

int main()
{
  auto magicPowerPerSection = readInput();
  auto entry = searchEntry(magicPowerPerSection);

  std::cout << entry;
}
