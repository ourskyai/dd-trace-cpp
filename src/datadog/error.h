#pragma once

#include <iosfwd>
#include <string>
#include <string_view>

namespace datadog {
namespace tracing {

struct Error {
  // Don't change the integer values of the `Code` enumeration.
  // The idea is that the integer values can still be looked up across library
  // versions.
  enum Code {
    OTHER = 1,
    SERVICE_NAME_REQUIRED = 2,
    MESSAGEPACK_ENCODE_FAILURE = 3,
    CURL_REQUEST_FAILURE = 4,
    DATADOG_AGENT_NULL_HTTP_CLIENT = 5,
    DATADOG_AGENT_INVALID_FLUSH_INTERVAL = 6,
    NULL_COLLECTOR = 7,
    URL_MISSING_SEPARATOR = 8,
    URL_UNSUPPORTED_SCHEME = 9,
    URL_UNIX_DOMAIN_SOCKET_PATH_NOT_ABSOLUTE = 10,
    NO_SPAN_TO_EXTRACT = 11,
    NOT_IMPLEMENTED = 12,
    MISSING_SPAN_INJECTION_STYLE = 13,
    MISSING_SPAN_EXTRACTION_STYLE = 14,
    OUT_OF_RANGE_INTEGER = 15,
    INVALID_INTEGER = 16,
    MISSING_PARENT_SPAN_ID = 17,
    RATE_OUT_OF_RANGE = 18,
    TRACE_TAGS_EXCEED_MAXIMUM_LENGTH = 19,
    INCONSISTENT_EXTRACTION_STYLES = 20,
    MAX_PER_SECOND_OUT_OF_RANGE = 21,
    MALFORMED_TRACE_TAGS = 22,
    UNKNOWN_PROPAGATION_STYLE = 23,
    TAG_MISSING_SEPARATOR = 24,
    RULE_PROPERTY_WRONG_TYPE = 25,
    RULE_TAG_WRONG_TYPE = 26,
    RULE_WRONG_TYPE = 27,
    TRACE_SAMPLING_RULES_INVALID_JSON = 28,
    TRACE_SAMPLING_RULES_WRONG_TYPE = 29,
    TRACE_SAMPLING_RULES_SAMPLE_RATE_WRONG_TYPE = 30,
    TRACE_SAMPLING_RULES_UNKNOWN_PROPERTY = 31,
    SPAN_SAMPLING_RULES_INVALID_JSON = 32,
    SPAN_SAMPLING_RULES_WRONG_TYPE = 33,
    SPAN_SAMPLING_RULES_SAMPLE_RATE_WRONG_TYPE = 34,
    SPAN_SAMPLING_RULES_UNKNOWN_PROPERTY = 35,
    SPAN_SAMPLING_RULES_MAX_PER_SECOND_WRONG_TYPE = 36,
    SPAN_SAMPLING_RULES_FILE_IO = 37,
    CURL_REQUEST_SETUP_FAILED = 38,
    CURL_HTTP_CLIENT_SETUP_FAILED = 39,
    CURL_HTTP_CLIENT_NOT_RUNNING = 40,
    CURL_HTTP_CLIENT_ERROR = 41,
  };

  Code code;
  std::string message;

  std::string to_string() const;
  Error with_prefix(std::string_view) const;
};

std::ostream& operator<<(std::ostream&, const Error&);

}  // namespace tracing
}  // namespace datadog
