#ifndef LVZHENG_FIXME_CONNECTION_HPP
#define LVZHENG_FIXME_CONNECTION_HPP

#include <memory>

#include <boost/asio/ip/tcp.hpp>

#include "market.hpp"

namespace lvzheng {
namespace fixme {
	
class connection : public std::enable_shared_from_this<connection> {
public:
	virtual void start() = 0;

	virtual ~connection() = default;

protected:
	connection() = default;
};

std::shared_ptr<connection> create_connection(boost::asio::ip::tcp::socket&& sock, market& mark);

} } // namespace lvzheng::fixme

#endif // LVZHENG_FIXME_CONNECTION_HPP
