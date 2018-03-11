cmake_minimum_required(VERSION 3.2)

project(ipfilter  VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

add_executable(ip_filter_cli ipfilter.cpp)

set_target_properties(ip_filter_cli PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

install(TARGETS ip_filter_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_CONTACT vladimir.englisbox@gmail.com)

