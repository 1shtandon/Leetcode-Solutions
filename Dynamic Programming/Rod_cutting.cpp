int cutRod(vector<int> &price, int n)
{
  // consider as knapsack problem where you have to collect rods to make N and
  // have max price
  vector<vector<int>> dp(n, vector<int>(n + 1, 0));

  for (int i = 0; i <= n; i++)
  {
    dp[0][i] = i * price[0];
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      int not_pick = dp[i - 1][j];
      int pick = INT_MIN;

      if (i + 1 <= j)
      {
        pick = price[i] + dp[i][j - i - 1];
      }

      dp[i][j] = max(pick, not_pick);
    }
  }

  return dp[n - 1][n];
}
