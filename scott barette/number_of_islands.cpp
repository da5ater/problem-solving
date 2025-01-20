#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>> &grid, int r, int c, int rows, int columns)
{
    if (r < 0 || c < 0 || r > rows || c > columns || grid[r][c] == '0')
        return;

    grid[r][c] = '0';

    dfs(grid, r + 1, c, rows, columns);
    dfs(grid, r - 1, c, rows, columns);
    dfs(grid, r, c + 1, rows, columns);
    dfs(grid, r, c - 1, rows, columns);
}

int numIslands(vector<vector<char>> &grid)
{
    int count = 0;

    int rows = grid.size();
    int columns = grid[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                dfs(grid, i, j, rows, columns);
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<char>> g = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
    cout << numIslands(g);
}