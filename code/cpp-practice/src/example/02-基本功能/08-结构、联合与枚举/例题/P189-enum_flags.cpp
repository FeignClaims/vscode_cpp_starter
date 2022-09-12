#include <iostream>
enum class PrinterFlags {
  kAcknowledge = 1,
  kPaperEmpty = 2,
  kBusy = 4,
  kOutOfBlack = 8,
  kOutOfColor = 16,
  // ...
};

// 定义成 constexpr 函数，这样就可以用于常量表达式了
// 如，switch 中的 case
constexpr auto operator|(PrinterFlags a, PrinterFlags b) -> PrinterFlags {
  return static_cast<PrinterFlags>(static_cast<int>(a) | static_cast<int>(b));
}

constexpr auto operator&(PrinterFlags a, PrinterFlags b) -> PrinterFlags {
  return static_cast<PrinterFlags>(static_cast<int>(a) & static_cast<int>(b));
}

void g(PrinterFlags x) {
  switch (x) {
    case PrinterFlags::kAcknowledge:
      std::cout << "kAcknowledge\n";
      break;
    case PrinterFlags::kBusy:
      std::cout << "kBusy\n";
      break;
    case PrinterFlags::kPaperEmpty:
      std::cout << "kPaperEmpty";
      break;
    case (PrinterFlags::kOutOfBlack & PrinterFlags::kOutOfColor):
      std::cout << "kOutOfBlack & kOutOfColor\n";
      // ...
      break;
  }
}