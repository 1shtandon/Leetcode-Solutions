class Solution
{
public:
    // int fun(int row , int col , vector<vector<int>> &grid , vector<vector<int>> &dp)
    // {
    //     // base case
    //     if(row == 0 and col == 0)
    //         return dp[0][0] = grid[0][0];
    //     else if(row < 0 or col < 0)
    //         return INT_MAX;

    //     if(dp[row][col] != -1)
    //         return dp[row][col];

    //     return dp[row][col] = min(fun(row - 1 , col , grid , dp) , fun(row , col - 1 ,grid , dp)) + grid[row][col];
    // }

    int minPathSum(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        // vector<vector<int>> dp(rows , vector<int> (cols , 0));
        // space optimization
        vector<int> prev(cols, 0);
        vector<int> curr(cols, 0);

        prev[0] = grid[0][0];

        for (int j = 1; j < cols; j++)
        {
            prev[j] = prev[j - 1] + grid[0][j];
        }

        for (int i = 1; i < rows; i++)
        {
            curr[0] = prev[0] + grid[i][0];
            for (int j = 1; j < cols; j++)
            {
                curr[j] = min(prev[j], curr[j - 1]) + grid[i][j];
            }

            prev = curr;
        }

        return prev[cols - 1];
    }
};