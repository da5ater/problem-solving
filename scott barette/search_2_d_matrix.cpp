#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int low = 0;
    int high = n - 1;
    int mid = 0;
    int guess = 0;
    int level = 0;
    while (low <= high && level < m)
    {
        mid = low + (high - low) / 2;
        guess = matrix[level][mid];
        if (target < matrix[level][0])
        {
            return false;
        }
        else if (target > matrix[level][n - 1])
        {
            level++;
            low = 0;
            high = n - 1;
        }
        else if (guess > target)
        {
            high = mid - 1;
        }
        else if (guess < target)
        {
            low = mid + 1;
        }
        else if (guess == target)
        {
            return true;
        }
    }
    return false;
};

void T_main()
{
    vector<vector<int>> m1{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target1 = 3;
    assert(searchMatrix(m1, target1) == true);

    vector<vector<int>> m2{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target2 = 13;
    assert(searchMatrix(m2, target2) == false);

    vector<vector<int>> m3 = {{1}};
    int target3 = 1;
    int target4 = 0;

    assert(searchMatrix(m3, target3) == true);
    assert(searchMatrix(m3, target4) == false);

    vector<vector<int>> m4{{1}, {3}};
    int target5 = 3;
    int target6 = 0;

    assert(searchMatrix(m4, target5) == true);
    assert(searchMatrix(m4, target6) == false);
}

int main()
{
    T_main();
    return 0;
}