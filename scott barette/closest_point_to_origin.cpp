#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    double distance;
    vector<int> point;
    priority_queue<pair<double, vector<int>>> heap;
    vector<vector<int>> res;
    for (auto &x : points)
    {
        distance = sqrt(pow(x[0], 2) + pow(x[1], 2));
        heap.push({distance, x});

        if (heap.size() > k)
        {
            heap.pop();
        }
    }

    while (!heap.empty())
    {
        res.push_back(heap.top().second);
        heap.pop();
    }
    return res;
}

int main()
{
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    int k = 1;
    vector<vector<int>> res = kClosest(points, k);
    for (auto x : res)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }

    vector<vector<int>> points1 = {{3, 3}, {5, -1}, {-2, 4}};
    int k1 = 2;
    vector<vector<int>> res1 = kClosest(points1, k1);
    for (auto x : res1)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
}