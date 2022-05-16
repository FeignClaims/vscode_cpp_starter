template <typename T>
struct X {
  enum E1 { a, b };
  enum E2;        //\! 基础类型未知
  enum class E3;  //\; class enum 的基础类型默认为 int
  enum E4 : char;

  struct C1 { /*...*/
  };
  struct C2;
};

template <typename T>
enum class X<T>::E3 {
  a,
  b
};
;  // 必需的

template <typename T>
enum class X<T>::E4 : char {
  x,
  y
};  // 必需的

template <typename T>
struct X<T>::C2 { /*...*/
};                // 必需的