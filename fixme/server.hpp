#ifndef LVZHENG_FIXME_SERVER_HPP
#define LVZHENG_FIXME_SERVER_HPP

#include <memory>

#include "options.hpp"

namespace lvzheng {
namespace fixme {

class server {
public:
	virtual int run() = 0;
	virtual ~server() = default;

protected:
	server() = default;
};

std::unique_ptr<server> create_server(const options& opts);

} } // namespace lvzheng::fixme

#endif // LVZHENG_FIXME_SERVER_HPP
