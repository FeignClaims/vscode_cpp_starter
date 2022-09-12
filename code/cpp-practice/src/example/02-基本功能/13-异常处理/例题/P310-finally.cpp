#include <cstdlib>
#include <iostream>
#include <memory>
template <typename F>
struct FinalAction {
  explicit FinalAction(F f) : clean{f} {}
  ~FinalAction() { clean(); }
  F clean;
};

template <typename F>
auto finally(F f) -> FinalAction<F> {
  return FinalAction<F>(f);
}

// 处理非常规的资源请求任务
// 该代码证明我们可以在其中嵌入任意操作
auto main() -> int {
  int* p{new int{7}};
  int* buf{
      static_cast<int*>(std::malloc(100 * sizeof(int)))};  // C 风格的资源请求

  auto act1 = finally([&] {
    delete p;
    free(buf);  // C 风格的资源释放
    std::cout << "Goodbye, cruel world!\n";
  });
  int var{0};

  // 嵌套的块：
  {
    var = 1;
    auto act2 = finally([&] {
      std::cout << "Finally!\n";
      var = 7;
    });
    std::cout << "var = " << var << '\n';
  }  // 调用 act2
  std::cout << "var = " << var << '\n';
}  // 调用 act1