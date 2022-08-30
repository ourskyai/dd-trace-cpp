#include "error.h"

#include <ostream>
#include <sstream>

namespace datadog {
namespace tracing {

std::ostream& operator<<(std::ostream& stream, const Error& error) {
  return stream << "[error code " << int(error.code) << "] " << error.message;
}

std::string Error::to_string() const {
  std::ostringstream stream;
  stream << *this;
  return stream.str();
}

Error Error::with_prefix(std::string_view prefix) const {
  std::string new_message{prefix.begin(), prefix.end()};
  new_message += message;
  return Error{code, std::move(new_message)};
}

}  // namespace tracing
}  // namespace datadog
