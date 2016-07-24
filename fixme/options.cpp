#include "options.hpp"

#include <boost/program_options/errors.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>

#include "exceptions.hpp"

namespace lvzheng {
namespace fixme {

options options::parse_file(std::istream& is)
{
	namespace po = boost::program_options;
	po::options_description desc;
	desc.add_options()
		("listen_addr", po::value<std::string>(), "address to listen")
		("listen_port", po::value<std::uint16_t>(), "port to listen")
	;

	po::variables_map vm;

	try {
		po::store(po::parse_config_file(is, desc), vm);
		po::notify(vm);
	} catch (boost::program_options::error& e) {
		throw bad_option(e.what());
	}

	if (!vm.count("listen_addr"))
		throw bad_option("option listen_addr missing");
	if (!vm.count("listen_port"))
		throw bad_option("option listen_port missing");

	options opt;
	opt.listen_addr = vm["listen_addr"].as<std::string>();
	opt.listen_port = vm["listen_port"].as<std::uint16_t>();

	return opt;
}


} } // namespace lvzheng::fixme
