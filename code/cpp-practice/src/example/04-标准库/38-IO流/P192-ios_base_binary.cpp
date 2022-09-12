#include <fstream>
#include <vector>
auto as_bytes(auto& i) -> char* {
  return reinterpret_cast<char*>(&i);  // 将内存中的数据以字节处理
}

void test() {
  std::ifstream ifs("source", std::ios_base::binary);  // 以二进制方式打开流
  std::ofstream ofs("target", std::ios_base::binary);  // 以二进制方式打开流

  std::vector<int> v;

  for (int i{}; ifs.read(as_bytes(i), sizeof(i));) {  // 从二进制文件读取字节
    v.push_back(i);
  }

  // ...对 v 进行一些处理 ...

  for (auto i : v) {  // 向二进制文件写入字节
    ofs.write(as_bytes(i), sizeof(i));
  }
}