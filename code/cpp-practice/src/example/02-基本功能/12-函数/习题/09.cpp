#include <utility>

void revert(char** a, std::pair<int, int> dimension) {
  for (int i{}; i < dimension.first; ++i) {
    for (int j{i}; j < dimension.second; ++j) {
      std::swap(a[i * dimension.second + j], a[j * dimension.second + i]);
    }
  }
}