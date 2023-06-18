class Solution
{
public:
    int mod = 1e9 + 7;

    int dfs(vector<vector<int>> &grid, int i, int j, int parent, vector<vector<int>> &dp)
    {
        int n = grid.size() , m = grid[0].size();

        if (i < 0 or i >= n or j < 0 or j >= m or grid[i][j] <= parent)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // now grid[i][j] as parent, travel all directions
        int up = dfs(grid, i - 1, j, grid[i][j], dp) % mod;
        int down = dfs(grid, i + 1, j, grid[i][j], dp) % mod;
        int left = dfs(grid, i, j - 1, grid[i][j], dp) % mod;
        int right = dfs(grid, i, j + 1, grid[i][j], dp) % mod;

        // summing up all the answers from neighbour with + 1 for that single elemental path itself
        return dp[i][j] = (up % mod + down % mod + left % mod + right % mod + 1) % mod;
    }

    int countPaths(vector<vector<int>> &grid)
    {

        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dp[i][j] == -1)
                {
                    dfs(grid, i, j, -1, dp);
                }
            }
        }

        long long res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                res += dp[i][j] % mod;
            }
        }

        return res % mod;
    }
};