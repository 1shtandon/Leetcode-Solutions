class Solution
{
public:
    // int fun(int row , int col , vector<vector<int>> &grid , vector<vector<int>> &dp)
    // {
    //     if(row == 0 and col == 0 and grid[0][0] != 1)
    //         return dp[0][0] = 1;

    //     if(row < 0 or col < 0 or grid[row][col] == 1)
    //         return 0;

    //     if(dp[row][col] != -1)
    //         return dp[row][col];

    //     return dp[row][col] = fun(row - 1 , col , grid , dp) + fun(row , col - 1 , grid , dp);
    // }

    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        // vector<vector<int>> dp(rows , vector<int> (cols , 0));

        // space optimization
        vector<int> prev(cols, 0);
        vector<int> curr(cols, 0);

        prev[0] = (grid[0][0] == 1) ? 0 : 1;
        // cout << dp[0][0] << endl;

        // for(int i = 1; i < rows; i++)
        // {
        //     if(grid[i][0] != 1)
        //         dp[i][0] = dp[i - 1][0];
        // }

        for (int i = 1; i < cols; i++)
        {
            prev[i] = (grid[0][i] == 1) ? 0 : prev[i - 1];
        }

        for (int i = 1; i < rows; i++)
        {
            curr[0] = (grid[i][0] == 1) ? 0 : prev[0];

            for (int j = 1; j < cols; j++)
            {

                curr[j] = (grid[i][j] == 1) ? 0 : prev[j] + curr[j - 1];
            }

            prev = curr;
        }

        return prev[cols - 1];
    }
};