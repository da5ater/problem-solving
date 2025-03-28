#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int dfs(int r, int c, int rows, int columns, vector<vector<int>> &grid)
{
    if (r >= rows || c >= columns)
        return 0;

    if (grid[r][c] > 0)
        return grid[r][c];

    if (r == rows - 1 || c == columns - 1)
    {
        return 1;
    }

    grid[r][c] = dfs(r + 1, c, rows, columns, grid) + dfs(r, c + 1, rows, columns, grid);
    return grid[r][c];
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> grid(m, vector<int>(n, 0));
    return dfs(0, 0, m, n, grid);
}

int main()
{
    // Test case 1  // 28
    cout << "Test 1: " << uniquePaths(3, 7) << endl;

    // Test case 2 // 3
    cout << "Test 2: " << uniquePaths(3, 2) << endl;

    // Test case 3 // 28
    cout << "Test 3: " << uniquePaths(7, 3) << endl;

    // Test case 4  // 6
    cout << "Test 4: " << uniquePaths(3, 3) << endl;

    return 0;
}