#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void insertion_sort(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int MinIndex = i;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[MinIndex])
                MinIndex = j;
        }

        if (i != MinIndex)
            swap(nums[i], nums[MinIndex]);
    }
}

int missingNumber(vector<int> &nums)
{
    insertion_sort(nums);
    int l = 0;
    int mid = 0;
    int guess = 0;
    int h = nums.size() - 1;
    while (l <= h)
    {
        mid = l + (h - l) / 2;

        if (nums[mid] == mid)
        {
            guess = nums[mid] + 1;
            l = mid + 1;
        }
        else
        {
            guess = nums[mid] - 1;
            h = mid - 1;
        }
    }
    return guess;
};

void test()
{
    vector<int> vec1 = {3, 1, 0};
    assert(missingNumber(vec1) == 2);

    vector<int> vec2 = {0};
    assert(missingNumber(vec2) == 1);
}

int main()
{
    test();
    vector<int> vec2 = {0};
    cout << missingNumber(vec2);
}