#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

void printGrid(const vector<vector<int>> &grid)
{
    for (const auto &row : grid)
    {
        for (int cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}

int orangesRotting(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int columns = grid[0].size();

    vector<vector<int>> directions = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };

    vector<vector<int>> visited(rows, vector<int>(columns, 0));

    queue<pair<int, int>>
        q;
    int minutes = -1;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            if (grid[r][c] == 2)
            {
                q.push({r, c});
            }
        }
    }

    while (!q.empty())
    {
        int level_size = q.size();

        for (int i = 0; i < level_size; i++)
        {
            auto [r, c] = q.front();
            q.pop();

            for (auto &dir : directions)
            {
                int NEWR = r + dir[0];
                int NEWC = c + dir[1];

                if (NEWR >= 0 && NEWR < rows && NEWC >= 0 && NEWC < columns && !visited[NEWR][NEWC] && grid[NEWR][NEWC] == 1)
                {
                    q.push({NEWR, NEWC});
                    grid[NEWR][NEWC] = 2;
                }
            }
        }

        minutes++;
        cout << minutes << endl;

        // printGrid(grid);
    }

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            if (grid[r][c] == 1)
            {
                return -1;
            }
        }
    }

    return minutes;
};

int main()
{

    // vector<vector<int>> grid = {{2, 1, 1},
    //                             {0, 1, 1},
    //                             {1, 0, 1}};
    // vector<vector<int>> grid = {{0, 2}};
    vector<vector<int>> grid = {{0}};

    cout << orangesRotting(grid);
}