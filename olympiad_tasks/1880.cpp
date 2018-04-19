//Task - http://acm.timus.ru/problem.aspx?space=1&num=1880

#include <iostream>     // std::cout
#include <algorithm>    // std::set_intersection, std::sort
#include <vector>       // std::vector

using eNumbersSequence = std::vector<size_t>;

auto readInput()
{
    std::vector<eNumbersSequence> personsENumbers;
    
    size_t inputNumbers = 0;
    while(std::cin >> inputNumbers)
    {
        std::vector<size_t> personENumbers;
        personENumbers.reserve(inputNumbers);
        
        while(inputNumbers--)
        {
            size_t eNumber = 0;
            std::cin >> eNumber;
            
            personENumbers.push_back(eNumber);
        }
        
        personsENumbers.push_back(personENumbers);
    }

    return personsENumbers;
}

auto getCommonValues(std::vector<eNumbersSequence> values)
{
  std::vector<size_t> commonValues;
    
  if(values.size() == 0)
      throw std::invalid_argument("size is 0");
    
  commonValues = values.at(0);

  for (auto& seq : values)
  {
      auto it = std::set_intersection(seq.begin(), seq.end(), commonValues.begin(), commonValues.end(), commonValues.begin());
      commonValues.resize(it - commonValues.begin());
  }

  return commonValues;
}

int main() {

    std::vector<eNumbersSequence> personsENumbers = readInput();  
    
    auto commonValues = getCommonValues(personsENumbers);
    
    std::cout << commonValues.size();  
}

// Version with different parsing.
// Almost work. Pass some tests, but not all.
/*

#include <iostream>     // std::cout
#include <algorithm>    // std::set_intersection, std::sort
#include <vector>       // std::vector
#include <string>
#include <iterator>

auto readInput()
{
  std::vector<std::string> values;

  std::string line;
  while (getline(std::cin, line))
    values.push_back(line);

  return values;
}

auto getValues(std::vector<std::string> values)
{
  std::vector<std::string> result;

  for (size_t i = 0; i < values.size(); ++i)
    if (i % 2 != 0)
      result.push_back(values[i]);

  return result;
}

auto prepareValues(std::vector<std::string> values)
{
  std::vector<std::vector<size_t>> result;

  for (const auto& str : values)
  {
    std::string delim = " ";

    auto start = 0U;
    auto end = str.find(delim);

    std::vector<size_t> clearValues;

    while (end != std::string::npos)
    {
      auto number = std::stoul(str.substr(start, end - start));
      start = end + delim.length();
      
      end = str.find(delim, start);
      
      clearValues.push_back(number);

      if (end == std::string::npos)
      {
        auto number = std::stoul(str.substr(start, str.size()));
        clearValues.push_back(number);
      }
    }

    result.push_back(clearValues);
  }

  return result;
}

auto getCommonValues(std::vector<std::vector<size_t>> values)
{
  std::vector<size_t> commonValues;

  if(values.size() == 0)
      throw std::invalid_argument("size is 0");
    
  commonValues = values.at(0);    
    
  for (auto& val : values)
  {
      auto it = std::set_intersection(val.begin(), val.end(), commonValues.begin(), commonValues.end(), commonValues.begin());
      commonValues.resize(it - commonValues.begin());
  }

  return commonValues;
}

int main() {

  auto inputValues = readInput();
  auto personsValues = getValues(inputValues);
  auto preparedValues = prepareValues(personsValues);

  for (auto& values : preparedValues)
    std::sort(values.begin(), values.end());

  auto commonValues = getCommonValues(preparedValues);

  std::cout << commonValues.size();

  return 0;
}
*/