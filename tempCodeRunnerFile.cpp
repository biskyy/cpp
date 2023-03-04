std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
  int x, y;
  for (int i = 0; i < numbers.size(); i++) {
    for (int j = 0; i < numbers.size(); j++) {
      if (numbers[i] + numbers[j] == target) {
        x = i;
        y = j;
      }
    }
  }
  return {x, y};
}