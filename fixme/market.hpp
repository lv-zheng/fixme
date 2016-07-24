#ifndef LVZHENG_FIXME_MARKET_HPP
#define LVZHENG_FIXME_MARKET_HPP

#include <memory>

namespace lvzheng {
namespace fixme {

class market {
public:
	virtual void start() = 0;
	virtual ~market() = default;

protected:
	market() = default;
};

std::unique_ptr<market> create_market();

} } // namespace lvzheng::fixme

#endif // LVZHENG_FIXME_MARKET_HPP
