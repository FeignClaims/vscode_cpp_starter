auto main() -> int {
  constexpr int kMaxLength = 10;
  char input_line[kMaxLength]{};
  int quest_count{};

  for (int i{}; i != kMaxLength; ++i) {
    if (input_line[i] == '?') {
      ++quest_count;
    }
  }

  int while_count{};
  while (while_count != kMaxLength) {
    if (input_line[while_count] == '?') {
      ++quest_count;
    }
    ++while_count;
  }

  for (char* i{input_line}; i != input_line + kMaxLength; ++i) {
    if (*i == '?') {
      ++quest_count;
    }
  }

  for (auto i : input_line) {
    if (i == '?') {
      ++quest_count;
    }
  }
}