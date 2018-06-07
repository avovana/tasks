// Task - http://acm.timus.ru/problem.aspx?space=1&num=1893&locale=en

#include <iostream>
#include <string>
#include <cctype>

int main()
{
    char symbol = 0;
    int rawNumber = 0;

    while(std::cin >> symbol)
    {
        if(std::isdigit(symbol))
        {
            int number = (symbol - '0');
            rawNumber = rawNumber  * 10 + number;
        }
    }

    std::string answer = "neither";

    if(rawNumber <= 2)
    {
        switch(symbol)
        {
            case 'A':
            case 'D':
                answer = "window"; 
                break;
                
            case 'B':
            case 'C':
                answer = "aisle"; 
                break;
                
            default:
                break;
        }
    }
    else if(rawNumber <= 20)
    {
        switch(symbol)
        {
            case 'A':
            case 'F':
                answer = "window"; 
                break;

            case 'B':
            case 'C':
            case 'D':
            case 'E':
                answer = "aisle"; 
                break;

            default:
                break;
        }
    }
    else
    {
        switch(symbol)
        {
            case 'A':
            case 'K':
                answer = "window"; 
                break;

            case 'C':
            case 'D':
            case 'G':
            case 'H':
                answer = "aisle"; 
                break;

            default:
                break;
        }
    }

    std::cout << answer << std::endl;
}
