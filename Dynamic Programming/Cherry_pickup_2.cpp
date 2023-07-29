// since every time they down for sure, so unlike the cherry pickup problem where we had 4d array, row can be common so we have 3d here
class Solution
{
public:
    int solve(int r, int c1, int c2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (r >= n or c1 >= m or c2 >= m or r < 0 or c1 < 0 or c2 < 0)
            return -1e9;

        if (dp[r][c1][c2] != -1)
            return dp[r][c1][c2];

        int cherries = grid[r][c1] + (c1 != c2 ? grid[r][c2] : 0);

        // 9 directions
        int maxCherries = 0;
        for (int nc1 = c1 - 1; nc1 <= c1 + 1; ++nc1)
        {
            for (int nc2 = c2 - 1; nc2 <= c2 + 1; ++nc2)
            {
                maxCherries = max(maxCherries, solve(r + 1, nc1, nc2, n, m, grid, dp));
            }
        }

        cherries += maxCherries;

        return dp[r][c1][c2] = cherries;
    }
    
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return max(0, solve(0, 0, m - 1, n, m, grid, dp));
    }
};
