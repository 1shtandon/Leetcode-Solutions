class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        // resembling to ninjas training

        for (int i = 0; i < rows; i++)
        {
            dp[0][i] = grid[0][i];
        }

        int mini = INT_MAX;

        for (int i = 1; i < rows; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                int ans = INT_MAX;
                for (int k = 0; k < rows; k++)
                {
                    if (j == k)
                        continue;
                    ans = min(ans, grid[i][j] + dp[i - 1][k]);
                }
                dp[i][j] = ans;
            }
        }
        for (int i = 0; i < grid[0].size(); i++)
        {
            mini = min(mini, dp[rows - 1][i]);
        }
        return mini;
    }
};
