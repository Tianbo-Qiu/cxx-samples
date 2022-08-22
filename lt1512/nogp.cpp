#include "nogp.h"
#include <unordered_map>

/**
 * time: O(n^2)
 * space: O(1)
 */
int nogp(std::vector<int> nums) {
  if (nums.size() < 2)
    return 0;
  int res = 0;
  for (int i = 0; i < nums.size(); ++i)
    for (int j = i + 1; j < nums.size(); ++j)
      if (nums[i] == nums[j])
        ++res;
  return res;
}

/**
 * It's actually just counting numbers...
 * time: O(n)
 * space: O(n)
 */
int nogp2(std::vector<int> nums) {
  int res = 0;
  std::unordered_map<int, int> count;
  for (int num : nums)
    res += count[num]++;
  return res;
}
