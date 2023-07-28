class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int dp[m][n];
        dp[0][0] = 1;
        // initialization
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = 1;
        }
        // computation
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        // ans
        return dp[m - 1][n - 1];
    }
};