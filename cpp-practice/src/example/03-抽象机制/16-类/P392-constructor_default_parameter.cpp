class Date {
 public:
  Date(int dd = 0, int mm = 0, int yy = 0);

 private:
  int d;
  int m;
  int y;
};

Date today{1, 1, 2000};

Date::Date(int dd, int mm, int yy)
    : d{dd ? dd : today.d}, m{mm ? mm : today.m}, y{yy ? yy : today.y} {
}