#include "src/lib.cpp"

#define BOOST_TEST_MODULE test_main

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_main)

BOOST_AUTO_TEST_CASE(test_bin_id)
{
  BOOST_REQUIRE( bin_id(1023) == 10 );
  BOOST_REQUIRE( bin_id(1024) == 10 );
  BOOST_REQUIRE( bin_id(1025) == 11 );
}

BOOST_AUTO_TEST_SUITE_END()
