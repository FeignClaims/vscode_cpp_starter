void send(int* to, int* from, int count)
// Duff ’s device. Helpful comment deliberately deleted.
{
  int n = (count + 7) / 8;
  switch (count % 8) {
    case 0:
      do {
        *to++ = *from++;
        case 7:
          *to++ = *from++;
        case 6:
          *to++ = *from++;
        case 5:
          *to++ = *from++;
        case 4:
          *to++ = *from++;
        case 3:
          *to++ = *from++;
        case 2:
          *to++ = *from++;
        case 1:
          *to++ = *from++;
      } while (--n > 0);
  }
}

auto main() -> int {
  int to{10};
  int from{5};
  int count{2};
  send(&to, &from, count);
}