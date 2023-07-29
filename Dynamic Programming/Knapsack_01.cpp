#include <bits/stdc++.h>

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{

    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    // for n = 1
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        dp[0][i] = value[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            int not_pick = dp[i - 1][j];

            int pick = 0;

            if (weight[i] <= j)
            {
                pick = value[i] + dp[i - 1][j - weight[i]];
            }

            dp[i][j] = max(not_pick, pick);
        }
    }

    return dp[n - 1][maxWeight];
}