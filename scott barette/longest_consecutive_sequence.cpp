#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> set(nums.begin(), nums.end());

    int count = 1;
    int max = 0;

    for (auto &x : set)
    {
        int temp = x;
        while (set.find(++temp) != set.end())
        {
            count++;
        }

        if (count > max)
            max = count;

        count = 1;
    }

    return max;
}

int main()
{
    vector<int> vec{100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(vec);
}