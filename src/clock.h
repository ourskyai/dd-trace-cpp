#pragma once

#include <chrono>
#include <functional>

namespace datadog {
namespace tracing {

struct TimePoint {
  std::chrono::system_clock::time_point wall =
      std::chrono::system_clock::time_point();
  std::chrono::steady_clock::time_point tick =
      std::chrono::steady_clock::time_point();

  using Duration = std::chrono::steady_clock::duration;
};

inline TimePoint::Duration operator-(const TimePoint& before,
                                     const TimePoint& after) {
  return after.tick - before.tick;
}

using Clock = std::function<TimePoint()>;

extern const Clock default_clock;

}  // namespace tracing
}  // namespace datadog
