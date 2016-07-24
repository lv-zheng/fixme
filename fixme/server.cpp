#include "server.hpp"

#include <iostream> // Currently only for debug purpose
#include <utility>

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>

#include "connection.hpp"
#include "market.hpp"

namespace lvzheng {
namespace fixme {

namespace impl {

#define IMPL server_impl

class IMPL final : public server {
public:
	IMPL(const options& opts);
	int run() override;

	~IMPL() override = default;

private:
	options _opts;
	boost::asio::io_service _io;
	boost::asio::ip::tcp::acceptor _acceptor;
	boost::asio::ip::tcp::socket _sock;
	std::unique_ptr<market> _market;

	void _do_accept();
};

IMPL::IMPL(const options& opts):
	_opts(opts),
	_acceptor(_io),
	_sock(_io)
{
	_market = create_market();

	boost::asio::ip::tcp::resolver resolver(_io);
	boost::asio::ip::tcp::endpoint ep = *resolver.resolve({_opts.listen_addr, std::to_string(_opts.listen_port)});
	_acceptor.open(ep.protocol());
	_acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
	_acceptor.bind(ep);
}

int IMPL::run()
{
	_acceptor.listen();
	_market->start();
	_do_accept();
	_io.run();
	return 0;
}

void IMPL::_do_accept()
{
	_acceptor.async_accept(_sock,
		[this](boost::system::error_code ec) {
			if (!_acceptor.is_open())
				return;
			if (!ec) {
				create_connection(std::move(_sock), *_market)->start();
			}
			_do_accept();
		}
	);
}

} // namespace impl

std::unique_ptr<server> create_server(const options& opts)
{
	return std::make_unique<impl::IMPL>(opts);
}

} } // namespace lvzheng::fixme
