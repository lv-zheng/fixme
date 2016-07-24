#include "market.hpp"

namespace lvzheng {
namespace fixme {

namespace impl {

#define IMPL market_impl

class IMPL : public market {
public:
	void start() override;

	~IMPL() override = default;
	
	IMPL();
};

IMPL::IMPL()
{
	// NOP
}

void IMPL::start()
{
	// TODO: market does nothing by now.
}

} // namespace impl

std::unique_ptr<market> create_market()
{
	return std::make_unique<impl::IMPL>();
}


} } // namespace lvzheng::fixme
