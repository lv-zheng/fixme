#include "parser.hpp"

#include <algorithm>
#include <deque>
#include <exception>
#include <iostream>
#include <string>

#include "fields.hpp"

namespace lvzheng {
namespace fixme {

namespace impl {

#define IMPL parser_impl

class IMPL : public parser {
public:
	void feed(const void *buf, std::size_t len) override;
	~IMPL() override = default;

	IMPL(market& mark, feedback_func fdb);

private:
	std::deque<unsigned char> _ibuf;
	feedback_func _fdb;
	market& _mark;

	static constexpr unsigned char SOH = 0x01;
	static constexpr unsigned long too_long = 1024;

	void _parse_item(const std::string& s);
	unsigned long _parse_ul(const std::string& s);

	struct bad_msg : std::runtime_error {
		bad_msg():std::runtime_error(""){}
	};

	struct fsm_t {
		enum state_t {
			// Standard Header
			NEW_MSG,
			BeginString = NEW_MSG,
			BodyLength,
			MsgType,
			SenderCompID,
			TargetCompID,
			Optional_1,
			MsgSeqNum,
			SenderSubID,
			Optional_2,
			SendingTime,

			// Body
			Body,

			// Standard Trailer
			Optional_3,
			Checksum,
		} state = NEW_MSG;
		unsigned bodylength = 0;
		unsigned bodylen_read = 0;
	} _fsm;
};

constexpr unsigned char IMPL::SOH;

IMPL::IMPL(market& mark, parser::feedback_func fdb):
	_mark(mark),
	_fdb(fdb)
{
	// NOP
}

void IMPL::feed(const void *vbuf, std::size_t len)
{
	const unsigned char *buf = static_cast<const unsigned char *>(vbuf);
	_ibuf.insert(_ibuf.end(), buf, buf + len);

	while (1) {
		auto it = std::find(_ibuf.begin(), _ibuf.end(), SOH);
		if (it == _ibuf.end())
			break;
		std::string s{_ibuf.begin(), it};
		_ibuf.erase(_ibuf.begin(), ++it);
		try {
			_parse_item(s);
		} catch (bad_msg&) {
			std::cout << "Invalid FIX message." << std::endl;
			_fdb(nullptr, 0);
		}
	}

	if (_ibuf.size() > too_long) {
		std::cout << "Message too long without SOH." << std::endl;
		_fdb(nullptr, 0);
	}
}

void IMPL::_parse_item(const std::string& s)
{
	// Unfinished function

	auto epos = s.find('=');
	if (epos == std::string::npos)
		throw bad_msg();
	unsigned long tag = _parse_ul(s.substr(0, epos));
	auto tit = field_str.find(tag);
	if (tit == field_str.end())
		throw bad_msg();

	std::string value = s.substr(epos + 1);

	std::cout << tit->second << " = " << value << std::endl;
	switch (_fsm.state) {
	case fsm_t::BeginString:
		std::cout << "New message received." << std::endl;
		if (tag != static_cast<unsigned long>(field_type::BeginString))
			throw bad_msg();
		_fsm.state = fsm_t::BodyLength;
		break;
	case fsm_t::BodyLength:
		if (tag != static_cast<unsigned long>(field_type::BodyLength))
			throw bad_msg();
		_fsm.bodylen_read = 0;
		_fsm.bodylength = _parse_ul(value);
		_fsm.state = fsm_t::Body;
		break;
	case fsm_t::Body:
		_fsm.bodylen_read += s.size() + 1;
		if (_fsm.bodylen_read >= _fsm.bodylength) {
			if (_fsm.bodylen_read != _fsm.bodylength)
				throw bad_msg();
			_fsm.state = fsm_t::Checksum;
		}
		break;
	case fsm_t::Checksum:
		std::cout << "Message ended." << std::endl;
		_fsm.state = fsm_t::BeginString;
		break;
	default:;
	}
}

unsigned long IMPL::_parse_ul(const std::string& s)
{
	unsigned long ans;
	std::size_t pos;
	try {
		ans = std::stoul(s, &pos);
	} catch (std::runtime_error&) {
		throw bad_msg();
	}
	if (pos != s.size())
		throw bad_msg();
	return ans;
}

} // namespace impl

std::unique_ptr<parser> create_parser(market& mark, parser::feedback_func fdb)
{
	return std::make_unique<impl::IMPL>(mark, fdb);
}

} } // namespace lvzheng::fixme::consts
