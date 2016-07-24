#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "consts.hpp"
#include "exceptions.hpp"
#include "options.hpp"
#include "server.hpp"

static void usage(const char *prog)
{
	std::cerr << "Usage: " << prog << " -c <config_file>" << std::endl;
	std::exit(1);
}

int main(int argc, char **argv)
{
	namespace fixme = lvzheng::fixme;

	std::cerr << "fixme (version "
		<< lvzheng::fixme::consts::version_str
		<< ")" << std::endl;
	std::cerr << "Copyright (C) 2016 Zheng Lv <lv.zheng.2015@gmail.com>"
		<< std::endl;
	std::cerr << "This is an incomplete work of FIX server." << std::endl;

	// Check cmdline options
	if (argc != 3 || std::strcmp(argv[1], "-c"))
		usage(argv[0]);

	// Open option file
	std::ifstream option_file(argv[2]);
	if (!option_file) {
		std::cerr << "Error: cannot open option file " << argv[2] << std::endl;
		return 1;
	}

	// Parse option file
	fixme::options opts;
	try {
		opts = fixme::options::parse_file(option_file);
	} catch (fixme::bad_option& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	// Start server
	std::unique_ptr<fixme::server> server = create_server(opts);
	int status = server->run();

	return status;
}
