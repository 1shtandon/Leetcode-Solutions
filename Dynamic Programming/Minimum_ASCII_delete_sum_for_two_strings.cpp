class Solution
{
public:
    int minimumDeleteSum(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            dp[i][0] = dp[i - 1][0] + word1[i - 1];
        }
        for (int j = 1; j <= n; j++)
        {
            dp[0][j] = dp[0][j - 1] + word2[j - 1];
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                else
                {
                    dp[i][j] = min(dp[i - 1][j] + word1[i - 1], dp[i][j - 1] + word2[j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};