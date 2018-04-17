#include "print_ip.h"

int main()
{
	print_ip(char(-1));
	print_ip(short(0));
	print_ip(2130706433);
	print_ip(long(8875824491850138409));
	print_ip("192.168.0.1");
	print_ip(std::list<int>{10, 0, 254, 2});
	print_ip(std::vector<int>{255, 255, 0, 0});
}