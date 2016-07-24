#ifndef LVZHENG_FIXME_PARSER_HPP
#define LVZHENG_FIXME_PARSER_HPP

#include <functional>
#include <memory>

#include "market.hpp"

namespace lvzheng {
namespace fixme {

class parser {
public:
	using feedback_func = std::function<void(const void *, std::size_t)>;
	virtual void feed(const void *buf, std::size_t len) = 0;

	virtual ~parser() = default;

protected:
	parser() = default;
};

std::unique_ptr<parser> create_parser(market& mark, parser::feedback_func fdb);

} } // namespace lvzheng::fixme::consts

#endif // LVZHENG_FIXME_PARSER_HPP
