#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

int count1s(vector<int> &x)
{
    int l = 0;
    int h = x.size() - 1;
    int mid = 0;
    int guess = 0;
    int index = 0;
    while (l <= h)
    {
        mid = l + (h - l) / 2;
        guess = x[mid];
        if (guess == 1)
        {
            l = mid + 1;
        }
        else
        {
            index = mid;
            h = mid - 1;
        }
    }
    return (index == 0) ? x.size() : index;
}

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> temp;
    vector<int> indecies;
    for (int i = 0; i < mat.size(); i++)
    {
        int priority = count1s(mat[i]);
        temp.push({priority, i});
    }
    for (int i = 0; i < k; i++)
    {
        pair<int, int> in = temp.top();
        indecies.push_back(in.second);
        temp.pop();
    }
    return indecies;
}

void test()
{
    vector<vector<int>> x = {{1, 0}, {1, 0}, {1, 0}, {1, 1}};
    vector<int> temp = {0, 1, 2, 3};
    assert(kWeakestRows(x, 4) == temp);
}

int main()
{
    test();
}