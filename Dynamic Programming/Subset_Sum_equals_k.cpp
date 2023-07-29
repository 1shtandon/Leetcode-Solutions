#include <bits/stdc++.h>

bool recursion(int ind, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    // base cases
    if (k == 0)
        return true;
    if (ind == 0)
        return arr[0] == k;

    if (dp[ind][k] != -1)
        return dp[ind][k];

    bool not_take = recursion(ind - 1, k, arr, dp);
    bool take = false;

    if (k >= arr[ind])
    {
        take = recursion(ind - 1, k - arr[ind], arr, dp);
    }

    return dp[ind][k] = take or not_take;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return recursion(n - 1, k, arr, dp);
}

/*
Tabulation
*/

#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int not_take = dp[i - 1][j];
            int take = 0;
            if (j >= arr[i])
                take = dp[i - 1][j - arr[i]];

            dp[i][j] = take or not_take;
        }
    }

    return dp[n - 1][k];
}