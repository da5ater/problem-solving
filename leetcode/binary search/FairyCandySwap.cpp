#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>
#include <algorithm>

using namespace std;

bool BS(int look_up_val, vector<int> &b)
{
    int low = 0;
    int high = b.size() - 1;
    int mid = 0;
    int guess = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        guess = b[mid];
        if (guess == look_up_val)
            return true;

        if (guess > look_up_val)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}

vector<int> arr(vector<int> &a, vector<int> &b, int target, bool alice_first, int sum)
{
    sort(b.begin(), b.end());

    for (auto &i : a)
    {
        int look_up_val = target - sum + i;
        if (BS(look_up_val, b))
            return (alice_first) ? vector<int>{i, look_up_val} : vector<int>{look_up_val, i};
    }
    return vector<int>{-1};
}

vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes)
{
    int alice_sum = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
    int bob_sum = accumulate(bobSizes.begin(), bobSizes.end(), 0);
    int target = (alice_sum + bob_sum) / 2;

    return (alice_sum < bob_sum) ? arr(aliceSizes, bobSizes, target, true, alice_sum) : arr(bobSizes, aliceSizes, target, false, bob_sum);
}

void t_main()
{

    vector<int> aliceSizes = {1, 1};
    vector<int> bobSizes = {2, 2};
    vector<int> ans = {1, 2};
    assert(fairCandySwap(aliceSizes, bobSizes) == ans);

    vector<int> aliceSizes1 = {1, 2};
    vector<int> bobSizes1 = {2, 3};
    vector<int> ans1 = {1, 2};
    assert(fairCandySwap(aliceSizes1, bobSizes1) == ans1);

    vector<int> aliceSizes2 = {2};
    vector<int> bobSizes2 = {1, 3};
    vector<int> ans2 = {2, 3};
    assert(fairCandySwap(aliceSizes2, bobSizes2) == ans2);

    vector<int> aliceSizes3 = {2, 3};
    vector<int> bobSizes3 = {1, 2};
    vector<int> ans3 = {2, 1};
    assert(fairCandySwap(aliceSizes3, bobSizes3) == ans3);
}

int main()
{
    t_main();
}