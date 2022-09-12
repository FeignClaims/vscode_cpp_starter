#include <iostream>

// STAR: 传递 C 风格多维数组的方式

void print_m35(int m[3][5]);
void print_mi5(int m[][5], int dim1);
void print_mij(int* m, int dim1, int dim2);

auto main() -> int {
  int v[3][5]{{0, 1, 2, 3, 4}, {10, 11, 12, 13, 14}, {20, 21, 22, 23, 24}};

  print_m35(v);
  std::cout << '\n';
  print_mi5(v, 3);
  std::cout << '\n';
  print_mij(&v[0][0], 3, 5);
}

void print_m35(int m[3][5]) {
  for (int i{}; i != 3; ++i) {
    for (int j{}; j != 5; ++j) {
      std::cout << m[i][j] << '\t';
    }
    std::cout << '\n';
  }
}

void print_mi5(int m[][5], int dim1) {
  for (int i{}; i != dim1; ++i) {
    for (int j{}; j != 5; ++j) {
      std::cout << m[i][j] << '\t';
    }
    std::cout << '\n';
  }
}

void print_mij(int* m, int dim1, int dim2) {
  for (int i{}; i != dim1; ++i) {
    for (int j{}; j != dim2; ++j) {
      std::cout << m[i * dim2 + j] << '\t';
    }
    std::cout << '\n';
  }
}