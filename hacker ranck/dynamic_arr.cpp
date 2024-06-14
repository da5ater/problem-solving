#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // int n, q;
    // cin >> n >> q;
    int n = 2;
    int q = 5;

    vector<vector<int>> arr(n);

    int last_answer = 0;

    vector<vector<int>> queries = {
        {1, 0, 5},
        {1, 1, 7},
        {1, 0, 3},
        {2, 1, 0},
        {2, 1, 1}};

    for (int row = 0; row < q; row++)
    {
        if (queries[row][0] == 1)
        {
                }
        else
        {
        }
    }
}