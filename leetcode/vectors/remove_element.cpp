#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val) {
  int k = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != val) {
      swap(nums[i], nums[k]);
      k++;
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