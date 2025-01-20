#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0, subset, res);
        return res;
    }

private:
    void dfs(const vector<int> &nums, int i, vector<int> &subset, vector<vector<int>> &res)
    {
        if (i >= nums.size())
        {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums, i + 1, subset, res);
        subset.pop_back();
        dfs(nums, i + 1, subset, res);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = s.subsets(nums);
    for (auto &v : res)
    {
        cout << "[";
        for (auto &i : v)
        {
            cout << i << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}