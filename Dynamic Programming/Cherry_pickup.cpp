class Solution
{
private:
    int solve(int r1, int c1, int r2, int c2, int n, vector<vector<int>> &grid, vector<vector<vector<vector<int>>>> &dp)
    {
        if (r1 >= n || r2 >= n || c1 >= n || c2 >= n || r1 < 0 || r2 < 0 || c1 < 0 || c2 < 0 || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e9;
        if (dp[r1][c1][r2][c2] != -1)
            return dp[r1][c1][r2][c2];
        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];

        if (r2 == n - 1 && c2 == n - 1)
            return grid[r2][c2];

        int ans = 0;
        // if both are at same;
        if (r1 == r2 && c1 == c2)
            ans = grid[r1][c1];
        else
            ans = grid[r1][c1] + grid[r2][c2];

        ans += max(max(solve(r1 + 1, c1, r2 + 1, c2, n, grid, dp), solve(r1, c1 + 1, r2, c2 + 1, n, grid, dp)), max(solve(r1 + 1, c1, r2, c2 + 1, n, grid, dp), solve(r1, c1 + 1, r2 + 1, c2, n, grid, dp)));

        return dp[r1][c1][r2][c2] = ans;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {

        int n = grid.size();
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));
        return max(0, solve(0, 0, 0, 0, n, grid, dp));
    }
};