//
// File: is_conainer.test.cpp
//

#define BOOST_TEST_MODULE IsFundamentalTest
#include <boost/test/unit_test.hpp>

#include "print_ip.h"
#include <sstream>

// Функция должна распознавать нужные типы фундаментальных данных
BOOST_AUTO_TEST_CASE(PrintFundamentals) {

	std::stringstream result;

	print_ip(result, char(-1));
	print_ip(result, short(0));
	print_ip(result, 2130706433);
	print_ip(result, long(8875824491850138409));

	std::string outputData =
		"255"
		"0.0"
		"127.0.0.1"
		"123.45.67.89.101.112.131.41";

	BOOST_CHECK(result.str() == outputData);
}

// Функция должна распознавать нужные типы фундаментальных данных
BOOST_AUTO_TEST_CASE(PrintContainers) {

	std::stringstream result;
	std::string outputData = "10..0..254..2";

	print_ip(result, std::list<int>{10, 0, 254, 2});
	BOOST_CHECK(result.str() == outputData);

	std::stringstream result2;
	std::string outputData2 = "255..255..0..0";

	print_ip(result2, std::vector<int>{255, 255, 0, 0});
	BOOST_CHECK(result.str() == outputData2);
}

// Функция должна распознавать нужные тип строки
BOOST_AUTO_TEST_CASE(PrintString) {

	std::stringstream result;
	std::string outputData = "192.168.0.1";

	print_ip(result, "192.168.0.1");
	BOOST_CHECK(result.str() == outputData);
}