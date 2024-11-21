#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

int MinElm(vector<int> &nums)
{

    auto it = min_element(nums.begin(), nums.end());
    return distance(nums.begin(), it);
}

int BS(vector<int> &nums, int start, int end, int target)
{
    int mid = 0;
    int guess = 0;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        guess = nums[mid];

        if (guess > target)
        {
            end = mid - 1;
        }
        else if (guess < target)
        {
            start = mid + 1;
        }
        else if (guess == target)
        {
            return mid;
        }
    }
    return -1;
}
int search(vector<int> &nums, int target)
{
    int start = MinElm(nums);

    if (start != 0)
    {
        if (target >= nums[0])
        {
            if (target > nums[start - 1])
                return -1;

            return BS(nums, 0, start - 1, target);
        }
        else
        {
            return BS(nums, start, nums.size() - 1, target);
        }
    }
    else
    {
        return BS(nums, 0, nums.size() - 1, target);
    }
}

void t_main()
{

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    assert(search(nums, target) == 4);

    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 3;
    assert(search(nums1, target1) == -1);

    vector<int> nums2 = {1};
    int target2 = 0;
    assert(search(nums2, target2) == -1);

    vector<int> nums3 = {1};
    int target3 = 1;
    assert(search(nums3, target3) == 0);
}

void t_min()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    assert(MinElm(nums) == 4);

    vector<int> nums1 = {1};
    assert(MinElm(nums1) == 0);
}

int main()
{
    // t_min();
    t_main();
}