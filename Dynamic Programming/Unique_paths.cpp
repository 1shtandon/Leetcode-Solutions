class Solution
{
public:
    // int fun(int row , int col , vector<vector<int>> &dp)
    // {
    //     if(row == 0 or col == 0)
    //         return dp[row][col] = 1;

    //     if(dp[row][col] != -1)
    //         return dp[row][col];

    //     return dp[row][col] = fun(row - 1 , col , dp) + fun(row , col - 1 , dp);
    // }

    int uniquePaths(int m, int n)
    {
        // vector<vector<int>> dp(m , vector<int>(n , 0));
        vector<int> prev(n, 1);
        vector<int> curr(n, 0);

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                    curr[j] = 1;
                else
                    curr[j] = prev[j] + curr[j - 1];
            }
            prev = curr;
        }

        return prev[n - 1];
    }
};