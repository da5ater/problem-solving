#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int dfs(int r, int c, vector<vector<int>> &obstacleGrid, int rows, int columns, vector<vector<int>> grid)
{
    if (r >= rows || c >= columns)
        return 0;

    if (obstacleGrid[r][c] == 1)
        return 0;

    if (grid[r][c] > 0)
        return grid[r][c];

    if (r == rows - 1 && c == columns - 1)
        return 1;

    grid[r][c] = dfs(r + 1, c, obstacleGrid, rows, columns, grid) + dfs(r, c + 1, obstacleGrid, rows, columns, grid);
    return grid[r][c];
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    vector<vector<int>> grid(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
    return dfs(0, 0, obstacleGrid, obstacleGrid.size(), obstacleGrid[0].size(), grid);
}

int main()
{
    // Test case 1  // 2
    vector<vector<int>> grid1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << "Test 1: " << uniquePathsWithObstacles(grid1) << endl;

    // Test case 2 // 1
    vector<vector<int>> grid2 = {{0, 1}, {0, 0}};
    cout << "Test 2: " << uniquePathsWithObstacles(grid2) << endl;

    // Test case 3 // 0
    vector<vector<int>> grid3 = {{0, 0}, {1, 1}, {0, 0}};
    cout << "Test 3: " << uniquePathsWithObstacles(grid3) << endl;
}