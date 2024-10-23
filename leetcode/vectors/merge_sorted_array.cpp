#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
void shift_right(vector<int> &nums1, int i, int m) {
  int temp = 0;
  for (int top = m; top >= i; top--) {
    temp = top + 1;
    nums1[temp] = nums1[top];
  }
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
  int n2 = 0;
  for (int i = 0; i < nums1.size(); i++) {
    if (nums1[i] > nums2[n2]) {
      shift_right(nums1, i, m - 1);
      nums1[i] = nums2[n2];
      n2++;
    }
  }
};

int main() {
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  int m = 3;
  vector<int> nums2 = {2, 5, 6};
  int n = 3;

  merge(nums1, m, nums2, n);

  for (auto x : nums1) {
    cout << x << " ";
  }
}