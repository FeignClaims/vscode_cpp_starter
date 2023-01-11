// note: https://quick-bench.com/q/yGo0VvdRGK5Y66NKDIRMq_zN_sw
// note: https://build-bench.com/b/ktOFXQ9__JADv2JL9THF5TMY03Q
// note: https://godbolt.org/z/cnrzKr

#include <algorithm>
#include <array>
#include <stdexcept>
#include <string_view>

template <typename Key, typename Value, std::size_t size>
struct Map {
  std::array<std::pair<Key, Value>, size> data;

  [[nodiscard]] constexpr auto at(Key const& key) const -> Value {
    if (auto const itr{std::find_if(
            data.cbegin(), data.cend(), [&key] [[nodiscard]] (auto const& elem) { return elem.first == key; })};
        itr != data.cend()) {
      return itr->second;
    }
    throw std::range_error("Not Found");
  }
};

using namespace std::literals::string_view_literals;
static constexpr std::array<std::pair<std::string_view, int>, 8> color_values{{{"black"sv, 7},
                                                                               {"blue"sv, 3},
                                                                               {"cyan"sv, 5},
                                                                               {"green"sv, 2},
                                                                               {"magenta"sv, 6},
                                                                               {"red"sv, 1},
                                                                               {"white"sv, 8},
                                                                               {"yellow"sv, 4}}};

[[nodiscard]] auto lookup_value(std::string_view const color_name) -> int {
  /* static auto const map{
      std::map<std::string_view, int>{color_values.cbegin(),
                                      color_values.cend()}
  }; */
  static constexpr auto map{Map<std::string_view, int, color_values.size()>{color_values}};

  return map.at(color_name);
}