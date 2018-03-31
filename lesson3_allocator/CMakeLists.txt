cmake_minimum_required(VERSION 3.2)

project(allocator_project  VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

# set variables for directories with source code
set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")

add_executable(allocator ${SOURCE_PATH}/main.cpp)

add_library(forward_list ${SOURCE_PATH}/forward_list.cpp)
add_library(allocator_handmade ${SOURCE_PATH}/allocator.cpp)
add_library(arena ${SOURCE_PATH}/arena.cpp)

target_link_libraries(bin_id 
	forward_list
	allocator_handmade
	arena
)


set_target_properties(
  bin_id
  forward_list
  allocator_handmade
  arena
  PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

install(TARGETS allocator RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT vladimir.englisbox@gmail.com)

include(CPack)
