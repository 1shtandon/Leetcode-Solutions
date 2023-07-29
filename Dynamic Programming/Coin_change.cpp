class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // for 1 coin
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
            {
                dp[0][i] = i / coins[0];
            }
            else
            {
                dp[0][i] = INT_MAX;
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                int not_pick = dp[i - 1][j];

                int pick = INT_MAX;
                if (coins[i] <= j)
                {
                    pick = 1 + dp[i][j - coins[i]];
                }

                dp[i][j] = min(pick, not_pick);
            }
        }

        return dp[n - 1][amount] == INT_MAX ? -1 : dp[n - 1][amount];
    }
};