//
// File: is_conainer.test.cpp
//

#define BOOST_TEST_MODULE IsContainerTest
#include <boost/test/unit_test.hpp>

#include "is_container.h"

// Структура должна распознавать нужные типы контейнеров
BOOST_AUTO_TEST_CASE(DefineContainerRight) {

	BOOST_CHECK(is_stl_container<std::vector<int>>::value == true);
	BOOST_CHECK(is_stl_container<std::vector<int>const&>::value == true);
	BOOST_CHECK(is_stl_container<std::list<char>>::value == true);
}

// Структура должна распознавать не правильно введенные типы
BOOST_AUTO_TEST_CASE(DefineContainerError) {

	BOOST_CHECK(is_stl_container<int>::value == false);
	BOOST_CHECK(is_stl_container<char>::value == false);
	BOOST_CHECK(is_stl_container<unsigned long>::value == false);
}