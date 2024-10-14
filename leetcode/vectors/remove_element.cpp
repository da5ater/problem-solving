#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val) {
  int k = nums.size();
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == val) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[j] != val) {
          swap(nums[i], nums[j]);
          k--;
          break;
        }
      }
    } else if (nums[i] != val) {

      k--;
    }
  }
  return k;
}

int main() {
  vector<int> a = {0, 1, 2, 2, 3, 0, 4, 2};
  int k = removeElement(a, 2);
  cout << k << endl;

  for (auto x : a) {
    cout << x << " ";
  }
}