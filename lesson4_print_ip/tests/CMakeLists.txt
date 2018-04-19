if (BUILD_TESTING)
    find_package (Boost COMPONENTS unit_test_framework REQUIRED)

    add_executable(is_containter_test
        is_container.test.cpp
    )

	add_executable(print_ip_test
        print_ip.test.cpp
    )

    set_target_properties(
		is_containter_test
		print_ip_test
		
		PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIRS}
        INCLUDE_DIRECTORIES ${SOURCE_PATH}
        LINK_LIBRARIES ${Boost_LIBRARIES}
    )

    add_test(IsContainerTest is_containter_test)
	add_test(PrintIpTest print_ip_test)
endif()