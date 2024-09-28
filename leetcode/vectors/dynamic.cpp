#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 2; // the size of array to create
    int q = 5; // the number of queries, respectively.

    vector<vector<int>> arr(n);
    int LastAnswer = 0;

    vector<vector<int>> queries = {
        {1, 0, 5},
        {1, 1, 7},
        {1, 0, 3},
        {2, 1, 0},
        {2, 1, 1}};

    vector<int> result;

    for (int row = 0; row < q; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            int type = queries[row][0];
            int x = queries[row][1];
            int y = queries[row][2];

            if (type == 1) // Query: 1 x y
            {
                int idx = (x ^ LastAnswer) % n;
                arr[idx].push_back(y);
            }
            else // Query: 2 x y
            {
                int idx = (x ^ LastAnswer) % n;
                arr[idx][y % arr[idx].size()] = LastAnswer;
            }
        }
    }

    for (int row = 0; row < arr.size(); row++)
    {
        for (int column = 0; column < arr[row].size(); column++)
        {
            cout << arr[row][column] << " ";
        }
        cout << endl;
    };
}