class Date {
 public:
  explicit Date(int dd = 0, int mm = 0, int yy = 0);

  static void set_default(int dd,
                          int mm,
                          int yy);  // 将 default_date 设置为 Date{dd, mm, yy}
 private:
  static Date default_date;

  int d;
  int m;
  int y;
};

Date::Date(int dd, int mm, int yy)
    : d{dd ? dd : default_date.d},
      m{mm ? mm : default_date.m},
      y{yy ? yy : default_date.y} {
  // ... 检查 Date 是否合法 ...
}

Date Date::default_date{16, 12, 1770};

void Date::set_default(int d, int m, int y) {
  default_date = Date{d, m, y};
}