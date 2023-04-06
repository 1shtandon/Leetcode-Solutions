/*
Approach : Depth First Search

1. The lands on boundary of the grid can never be closed islands.
2. So first apply dfs on all boundary lands and change them to 2s.
3. Now, apply dfs on all 0s and count connected components.
4. Return the count.

Time Complexity: O(m*n)
Space Complexity: O(1)
*/

class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or grid[i][j] != 0)
            return;
        grid[i][j] = 2;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        int totalConnectedLands = 0, closedIslands = 0;
        for (int i = 0; i < rows; i++)
        {
            if (grid[i][0] == 0)
                dfs(grid, i, 0);
            if (grid[i][cols - 1] == 0)
                dfs(grid, i, cols - 1);
        }
        for (int j = 0; j < cols; j++)
        {
            if (grid[0][j] == 0)
                dfs(grid, 0, j);
            if (grid[rows - 1][j] == 0)
                dfs(grid, rows - 1, j);
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 0)
                {
                    closedIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        return closedIslands;
    }
};