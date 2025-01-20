#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &grid, int r, int c, int rows, int columns, int &max, int &count)
{
    if (r < 0 || c < 0 || r >= rows || c >= columns || grid[r][c] == 0)
    {
        return;
    }

    grid[r][c] = 0;
    count++;

    dfs(grid, r + 1, c, rows, columns, max, count);
    dfs(grid, r - 1, c, rows, columns, max, count);
    dfs(grid, r, c + 1, rows, columns, max, count);
    dfs(grid, r, c - 1, rows, columns, max, count);
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int columns = grid[0].size();
    int max = 0;

    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < columns; j++)
        {
            if (grid[i][j] == 1)
            {
                int count = 0;
                dfs(grid, i, j, rows, columns, max, count);
                if (count > max)
                    max = count;
            }
        }
    }
    return max;
}

int main()
{
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << maxAreaOfIsland(grid);
}