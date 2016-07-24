#ifndef LVZHENG_FIXME_OPTIONS_HPP
#define LVZHENG_FIXME_OPTIONS_HPP

#include <cstdint>
#include <istream>
#include <string>

namespace lvzheng {
namespace fixme {

struct options {
	std::string listen_addr;
	std::uint16_t listen_port;

	static options parse_file(std::istream& is);
};

} } // namespace lvzheng::fixme

#endif // LVZHENG_FIXME_OPTIONS_HPP
