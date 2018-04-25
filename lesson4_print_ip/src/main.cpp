#include "print_ip.h"
#include <sstream>

int main()
{
	try
	{
		print_ip(std::cout, char(-1));
		std::cout << std::endl;
		print_ip(std::cout, short(0));
		std::cout << std::endl;
		print_ip(std::cout, 2130706433);
		std::cout << std::endl;
		print_ip(std::cout, long(8875824491850138409));
		std::cout << std::endl;
		print_ip(std::cout, "192.168.0.1");
		std::cout << std::endl;
		print_ip(std::cout, std::list<int>{10, 0, 254, 2});
		std::cout << std::endl;
		print_ip(std::cout, std::vector<int>{255, 255, 0, 0});
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}