#include <bits/stdc++.h>

int recursion(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{

    // base case : single element
    if (i == j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int res = INT_MAX;
    //   forming different partitions
    for (int k = i; k < j; k++)
    {

        //   applying recursion for further partitions
        int steps = (arr[i - 1] * arr[k] * arr[j]) + recursion(i, k, arr, dp) +
                    recursion(k + 1, j, arr, dp);
        res = min(res, steps);
    }

    return dp[i][j] = res;
}

int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return recursion(1, n - 1, arr, dp);
}

/*
tabulation solution
*/

int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // base case
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }

    // for length 2 to n as we are building bottom up
    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;

            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int steps = (arr[i - 1] * arr[k] * arr[j]) + dp[i][k] + dp[k + 1][j];
                dp[i][j] = min(dp[i][j], steps);
            }
        }
    }

    return dp[1][n - 1];
}