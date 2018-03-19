cmake_minimum_required(VERSION 3.2)

project(bin_id  VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(bin_id bin_id.cpp)

add_library(bin_functions lib.cpp)
target_link_libraries(bin_id bin_functions)

add_executable(test_bin_func test_bin_id.cpp)

set_target_properties(
  bin_id
  bin_functions
  test_bin_func
  PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(test_bin_func PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(test_bin_func
  ${Boost_LIBRARIES}
  bin_functions 
)

install(TARGETS bin_id RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT vladimir.englisbox@gmail.com)

include(CPack)

enable_testing()

add_test(test_bin_id test_bin_func)
