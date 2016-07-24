#ifndef LVZHENG_FIXME_EXCEPTIONS_HPP
#define LVZHENG_FIXME_EXCEPTIONS_HPP

#include <exception>

namespace lvzheng {
namespace fixme {

struct exception : std::runtime_error {
	using std::runtime_error::runtime_error;
};

struct bad_option : exception {
	using exception::exception;
};

} } // namespace lvzheng::fixme

#endif // LVZHENG_FIXME_EXCEPTIONS_HPP
