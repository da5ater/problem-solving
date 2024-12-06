#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    vector<int> ans(2);
    for (int i = 0; i < nums.size(); i++)
    {
        auto find = map.find(target - nums[i]);

        if (find == map.end())
        {
            map[nums[i]] = i;
        }
        else
        {
            ans.push_back(i);
            ans.push_back(find->second);
            return ans;
        }
    }
    return ans;
}

int main()
{
}