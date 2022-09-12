#include <cstddef>
#include <iostream>
#include <locale>
#include <ostream>
#include <ranges>
#include <string>

enum class Season {
  kSpring,
  kSummer,
  kFall,
  kWinter
};  // 很简单的用户自定义类型

class SeasonIo : public std::locale::facet {
 public:
  explicit SeasonIo(std::size_t i = 0) : std::locale::facet{i} {}
  ~SeasonIo() override = default;  // 为了能销毁 SeasonIo 对象

  [[nodiscard]] virtual auto to_str(Season x) const
      -> const std::string& = 0;  // x 的字符串表示
  [[nodiscard]] virtual auto from_str(const std::string& s, Season& x) const
      -> bool = 0;  // 将 s 所表示的 Season 放置于 x 中

  static std::locale::id id;  // facet 标识对象
};

std::locale::id SeasonIo::id;  // 定义标识对象

auto operator<<(std::ostream& os, Season x) -> std::ostream& {
  std::locale loc{os.getloc()};  // 提取流的 locale

  if (std::has_facet<SeasonIo>(loc)) {
    return os << std::use_facet<SeasonIo>(loc).to_str(x);  // 字符串表示
  }
  return os << static_cast<int>(x);  // 整数表示
}

auto operator>>(std::istream& is, Season& x) -> std::istream& {
  const std::locale& loc{is.getloc()};  // 提取流的 locale

  if (std::has_facet<SeasonIo>(loc)) {
    const SeasonIo& f{
        std::use_facet<SeasonIo>(loc)};  // 获取 locale 的 SeasonIo facet

    std::string buf;
    if (!(is >> buf && f.from_str(buf, x))) {  // 读取字符串表示
      is.setstate(std::ios_base::failbit);
    }
    return is;
  }

  int i{};
  is >> i;  // 读取数值表示
  x = static_cast<Season>(i);
  return is;
}

// star: 为接口派生一个实现
//\* 也可以将季节字符串作为构造函数实参达到同样的效果
class UsSeasonIo : public SeasonIo {
 public:
  [[nodiscard]] auto to_str(Season /*x*/) const -> const std::string& override;
  auto from_str(const std::string& /*s*/, Season& /*x*/) const -> bool override;

 private:
  static const std::string seasons[];
};

const std::string UsSeasonIo::seasons[] = {
    "spring", "summer", "fall", "winter"};

auto UsSeasonIo::to_str(Season x) const -> const std::string& {
  if (x < Season::kSpring || Season::kWinter < x) {
    static const std::string ss{"no-such-season"};
    return ss;
  }
  return seasons[static_cast<int>(x)];
}

auto UsSeasonIo::from_str(const std::string& s, Season& x) const -> bool {
  const auto* p =
      std::find(std::ranges::begin(seasons), std::ranges::end(seasons), s);
  if (p == std::ranges::end(seasons)) {
    return false;
  }
  x = Season{static_cast<int>(p - std::ranges::begin(seasons))};
  return true;
}

auto main() -> int {
  Season x{};
  // 使用默认 locale（无 SeasonIo facet）意味着整数 I/O
  std::cin >> x;
  std::cout << x << '\n';

  std::locale loc(std::locale(), new UsSeasonIo{});
  std::cout.imbue(loc);  // 使用有 SeasonIo facet 的 locale
  std::cin.imbue(loc);   // 使用有 SeasonIo facet 的 locale

  std::cin >> x;
  std::cout << x << '\n';
}