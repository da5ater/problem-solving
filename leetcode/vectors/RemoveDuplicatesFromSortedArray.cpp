#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums) {
  int cmpr = nums[0];
  int length = 1;
  for (int i = 1; i < nums.size(); i++) {
    for (int j = i; j < nums.size(); j++) {
      if (nums[j] > cmpr) {
        nums[i] = nums[j];
        length++;
        cmpr = nums[j];
        break;
      }
    }
  }
  return length;
}

int main() {

  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  removeDuplicates(nums);
}