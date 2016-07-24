#include "connection.hpp"

#include <array>
#include <iostream>
#include <string>

#include "parser.hpp"

namespace lvzheng {
namespace fixme {

namespace impl {

#define IMPL connection_impl

class IMPL : public connection {
public:
	static constexpr unsigned ibufflen = 4096;

	~IMPL() override;

	IMPL(boost::asio::ip::tcp::socket&& sock, market& mark);

	void start() override;

private:
	boost::asio::ip::tcp::socket _sock;
	market& _mark;
	std::array<unsigned char, ibufflen> _ibuff;
	std::unique_ptr<parser> _ps;
	bool _closed = false;

	void _do_read();
	void _process_ibuff(std::size_t len);

	void _ps_feedback(const void *buf, std::size_t len);
};

IMPL::IMPL(boost::asio::ip::tcp::socket&& sock, market& mark):
	_sock(std::move(sock)),
	_mark(mark)
{
	// NOP
}

void IMPL::start()
{
	std::cout << "New connection established." << std::endl;
	// To avoid circular reference, don't pass shared_from_this() 
	parser::feedback_func f =
		[this](const void *buf, std::size_t len) {
			return _ps_feedback(buf, len);
		};

	_ps = create_parser(_mark, f);

	_do_read();
}

void IMPL::_do_read()
{
	auto self{shared_from_this()};
	_sock.async_read_some(boost::asio::buffer(_ibuff),
		[this, self](boost::system::error_code ec, std::size_t len) {
			if (_closed)
				return;
			if (ec) {
				_sock.close();
				_closed = true;
				return;
			}
			_process_ibuff(len);
			_do_read();
		}
	);
}

void IMPL::_process_ibuff(std::size_t len)
{
	_ps->feed(_ibuff.data(), len);
}

void IMPL::_ps_feedback(const void *buf, std::size_t len)
{
	// TODO: send data to client
	if (buf == nullptr) {
		std::cout << "Closing connection..." << std::endl;
		_sock.cancel();
		_sock.close();
		_closed = true;
	}
}

IMPL::~IMPL()
{
	std::cout << "Connection closed." << std::endl;
}

} // namespace impl

std::shared_ptr<connection> create_connection(boost::asio::ip::tcp::socket&& sock, market& mark)
{
	return std::make_shared<impl::IMPL>(std::move(sock), mark);
}

} } // namespace lvzheng::fixme
