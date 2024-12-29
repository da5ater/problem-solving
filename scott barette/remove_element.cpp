#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
    {
        if (nums[0] == val)
        {
            nums = {};
            return 0;
        }
        return 1;
    }
    int l = 0, r = 0;

    while (r < nums.size() - 1 || l < nums.size() - 2)
    {
        if (nums[r] != val)
        {
            swap(nums[l], nums[r]);
            l++;
            r = l;
        }
        else
        {
            r++;
        }
    }
    return l;
}

int main()
{
    vector<int> vec = {0,
                       1,
                       2,
                       2,
                       3,
                       0,
                       4,
                       2};

    cout << removeElement(vec, 2);
}