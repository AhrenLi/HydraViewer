#include <iostream>

#include "viewer/hv.h"
#include "viewer/utils/logger.h"

HV_NS_USING

int main() {
	// initialize logger
	Logger logger;

	LOG_TRACE("xxxx");

	LOG_INFO("xx:{}", 1);

	std::cout << "Hello Hydra Viewer!" << std::endl;

	return 0;
}