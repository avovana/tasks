cmake_minimum_required(VERSION 3.2)

project(bin_id  VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

add_executable(bin_id bin_id.cpp)

add_library(bin_functions lib.cpp)
target_link_libraries(bin_id bin_functions)

set_target_properties(
  bin_id
  bin_functions 
  PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

install(TARGETS bin_id RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT vladimir.englisbox@gmail.com)

include(CPack)
