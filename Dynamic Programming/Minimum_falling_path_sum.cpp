class Solution
{
public:
    // int fun(int row , int col , int n, vector<vector<int>> &matrix , vector<vector<int>> &dp)
    // {
    //     if(row < 0 or col < 0 or col >= n)
    //     {
    //         return INT_MAX;
    //     }

    //     if(row == 0)
    //     {
    //         return dp[0][col] = matrix[0][col];
    //     }

    //     if(dp[row][col] != -101)
    //         return dp[row][col];

    //     return dp[row][col] = matrix[row][col] + min({fun(row - 1 , col , n , matrix , dp) , fun(row - 1 , col - 1 , n , matrix, dp) , fun(row - 1, col + 1, n , matrix , dp)});
    // }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // vector<vector<int>> dp(n , vector<int> (n , 0));
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);

        if (n == 1)
            return matrix[0][0];

        for (int i = 0; i < n; i++)
        {
            prev[i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == n - 1)
                    curr[j] = matrix[i][j] + min(prev[j], prev[j - 1]);

                else if (j == 0)
                    curr[j] = matrix[i][j] + min(prev[j], prev[j + 1]);

                else
                    curr[j] = matrix[i][j] + min(prev[j], min(prev[j + 1], prev[j - 1]));
            }

            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};