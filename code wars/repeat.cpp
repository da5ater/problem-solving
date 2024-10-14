#include <iostream>
#include <vector>

using namespace std;

    int findSmallest(vector<int> list) {
    int min = INT_MAX;
    for (int i = 0; i < list.size(); i++) {
        if (list[i] < min)
        min = list[i];
    }
    return min;
    }

int main() {
  vector<int> a = {34, 15, 88, 2};
  cout << findSmallest(a);
}