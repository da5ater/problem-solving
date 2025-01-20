#include <iostream>

#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        if (rows == 0)
            return -1;
        int columns = grid[0].size();
        if (columns == 0)
            return -1;

        if (grid[0][0] == 1 || grid[rows - 1][columns - 1] == 1)
            return -1;

        vector<vector<int>> visited(rows, vector<int>(columns, 0));
        queue<std::pair<int, int>> q;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        q.push({0,
                0});
        visited[0][0] = 1;
        int length = 0;

        while (!q.empty())
        {
            int level_size = q.size();

            for (int i = 0; i < level_size; i++)
            {
                auto [r, c] = q.front();
                q.pop();

                if (r == 1 && c == 1)
                    return length;
                for (auto &dir : directions)
                {
                    int NEWR = r + dir[0];
                    int NEWC = c + dir[1];

                    if (NEWR >= 0 && NEWR < rows && NEWC >= 0 && NEWC < columns && visited[NEWR][NEWC] == 0 && grid[NEWR][NEWC] == 0)
                    {
                        q.push({NEWR,
                                NEWC});
                        visited[NEWR][NEWC] = 1;
                    }
                }
            }
            length++;
        }

        return length;
    };
};

int main()
{
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    Solution s;
    cout << s.shortestPathBinaryMatrix(grid);
}