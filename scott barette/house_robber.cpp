#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rec(vector<int> &nums, int index)
{
    if (index >= nums.size())
    {
        return 0;
    }

    int current = nums[index] + rec(nums, index + 2);
    int skip = rec(nums, index + 1);

    return max(skip, current);
}

int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];

    return rec(nums, 0);
}

int main()
{
    // Test case 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test 1: " << rob(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << "Test 2: " << rob(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {2, 1, 1, 2};
    cout << "Test 3: " << rob(nums3) << endl;

    return 0;
}