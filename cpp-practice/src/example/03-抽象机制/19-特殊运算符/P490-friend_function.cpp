constexpr int kRcMax{4};  // 行列的尺寸

class Matrix;

class Vector {
  float v[kRcMax];
  // ...
  friend auto operator*(const Matrix&, const Vector&) -> Vector;
};

class Matrix {
  Vector v[kRcMax];
  // ...
  friend auto operator*(const Matrix&, const Vector&) -> Vector;
};

auto operator*(const Matrix& m, const Vector& v) -> Vector {
  Vector r;
  for (int i{}; i != kRcMax; ++i) {  // r[i] = m[i] * v;
    r.v[i] = 0;
    for (int j{}; j != kRcMax; ++j) {
      r.v[i] += m.v[i].v[j] * v.v[j];
    }
  }
  return r;
}