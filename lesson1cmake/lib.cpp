#include <iostream>
#include "lib.h"

std::string version()
{
	std::string version = std::to_string(PROJECT_VERSION_MAJOR);
	version.append(".");
	version.append(std::string(PROJECT_VERSION_MINOR));
	version.append(".");
	version.append(std::string(PROJECT_VERSION_PATCH));
	
	return version;
}
