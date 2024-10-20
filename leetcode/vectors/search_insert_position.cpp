#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target) {
  int low = 0;
  int high = nums.size() - 1;
  int mid = 0;
  while (low < high) {
    mid = low + (high) / 2;

    if (nums[mid] == target)
      return mid;

    if (target < nums[mid])
      high = mid - 1;

    if (target > nums[mid]) {
      low = mid + 1;
    }
  }
  if (high == 0) {
    return (nums[0] < target) ? 1 : 0;
  }

  if (low == nums.size() - 1) {
    return (nums[nums.size() - 1] < target) ? nums.size() : nums.size() - 2;
  }
  return mid;
};

int main() {
  vector<int> x = {1, 3, 5, 6};
  int target = 7;
  cout << searchInsert(x, target);
}