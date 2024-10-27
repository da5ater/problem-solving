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
  int curr = nums1.size() - 1;
  m--;
  n--;
  while (n >= 0 && m >= 0) {
    if (nums2[n] >= nums1[m]) {
      nums1[curr] = nums2[n];
      n = n - 1;
      curr = curr - 1;
    } else if (nums2[n] < nums1[m]) {
      nums1[curr] = nums1[m];
      m = m - 1;
      curr = curr - 1;
    }
  }

  while (n >= 0) {
    nums1[curr] = nums2[n];
    n = n - 1;
    curr = curr - 1;
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