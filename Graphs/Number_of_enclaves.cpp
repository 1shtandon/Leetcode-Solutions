/*
Approach: Depth First Search

1. Apply DFS on all the 1s which are on the boundary of the grid and change them to 2s.
2. Now, count the number of 1s in the grid and return the count.

Time Complexity: O(m*n)
Space Complexity: O(1)
*/
class Solution
{
private:
    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or grid[i][j] != 1)
            return;
        grid[i][j] = 2;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        int totalLand = 0;
        for (int i = 0; i < rows; i++)
        {
            if (grid[i][0] == 1)
                dfs(grid, i, 0);
            if (grid[i][cols - 1] == 1)
                dfs(grid, i, cols - 1);
        }
        for (int j = 0; j < cols; j++)
        {
            if (grid[0][j] == 1)
                dfs(grid, 0, j);
            if (grid[rows - 1][j] == 1)
                dfs(grid, rows - 1, j);
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1)
                    totalLand++;
            }
        }
        return totalLand;
    }
};