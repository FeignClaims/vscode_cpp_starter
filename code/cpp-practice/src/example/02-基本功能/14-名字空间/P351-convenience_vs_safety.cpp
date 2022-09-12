namespace X {
int i, j, k;
}  // namespace X

int k;

void f1() {
  int i = 0;
  using namespace X;  // 令来自 X 的名字可访问
  i++;                // 局部 i
  j++;                // X::j
  k++;                // alert: X 的 k 还是全局的 k？
  ::k++;              // 全局 k
  X::k++;             // X 的 k
}

void f2() {
  int i = 0;
  using X::i;  // alert: i 在 f2() 中声明了两次
  using X::j;
  using X::k;  // 隐藏了全局 k

  i++;
  j++;  // X::j
  k++;  // X::k
}