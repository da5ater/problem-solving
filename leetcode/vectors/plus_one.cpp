#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits) {

  for (int i = digits.size() - 1; i >= 0; i--) {
    if (digits[i] == 9) {
      if (i == 0) {
        digits[i] = 0;
        digits.insert(digits.begin(), 1);
        return digits;
      } else {
        digits[i] = 0;
      }
    } else {
      digits[i]++;
      return digits;
    }
  }
};

int main() {
  vector<int> a{9, 9, 9};
  plusOne(a);
  for (int i : a) {
    cout << i << " ";
  }
}