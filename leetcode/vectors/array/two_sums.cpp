#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> out;
    unordered_map<int, int> um;
    for (int i = 0; i < nums.size(); i++)
    {
        if (um.count(target - nums[i]))
        {
            out.push_back(i);
            out.push_back(um.at(target - nums[i]));
        }
        else
        {
            um.insert({nums[i], i});
        }
    }
    return out;
}

int main()
{
    vector<int> nums{3, 3};
    twoSum(nums, 6);
}