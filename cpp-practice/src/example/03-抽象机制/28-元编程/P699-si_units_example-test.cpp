#include "P696-si_units_example-quantity.hpp"

#include <iostream>

auto main() -> int {
  auto distance = 10.0_m;        // 10 米
  auto time = 20.0_s;            // 20 秒
  auto speed = distance / time;  // .5 米 / 秒

  if (speed == 20) {  //\! 20 是无量纲的
    // ...
  }
  if (speed == distance) {  //\! 不能比较米和米 / 秒
    // ...
  }
  if (speed == 10.0_m / 20.0_s) {  //\; 单位匹配
    // ...
  }

  Quantity<MpS2> acceleration =
      distance / square(time);  // MpS2 表示米 /( 秒 * 秒)

  std::cout << "speed==" << speed << "acceleration==" << acceleration << '\n';
}