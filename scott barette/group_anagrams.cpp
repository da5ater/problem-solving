#include <iostream>
#include <cassert>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int bin(string st, unordered_map<string, int> &map, int &count)
{
    sort(st.begin(), st.end());

    auto it = map.find(st);

    if (it == map.end())
    {
        map[st] = count++;
        return map[st];
    }
    else
    {
        return map[st];
    }
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    int count = 0;
    unordered_map<int, int> map(1);
    vector<vector<string>> ans;
    for (auto &st : strs)
    {
        int i = bin(st, map, count);
        if (i >= ans.size())
        {

            ans.resize(i + 1);
        }

        ans[i].emplace_back(st);
    };
    return ans;
};

void t_main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>>
        strs1 = {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};

    assert(groupAnagrams(strs) == strs1);
}

int main()
{
    t_main();
}