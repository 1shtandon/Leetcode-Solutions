class Solution
{
public:
    // int fun(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    // {
    //     if(row < 0 or col < 0 or col >= triangle[row].size())
    //         return INT_MAX;

    //     if(dp[row][col] != -1)
    //         return dp[row][col];

    //     if(row == 0)
    //         return dp[row][col] = triangle[0][0];

    //     return dp[row][col] = triangle[row][col] + min(fun(row - 1, col, triangle, dp), fun(row - 1, col - 1, triangle, dp));
    // }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        // vector<vector<int>> dp(n , vector<int> (n , -10001));
        vector<int> prev(n, -10001);
        vector<int> curr(n, -10001);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (i == n - 1)
                {
                    prev[j] = triangle[i][j];
                }
                else
                {
                    prev[j] = triangle[i][j] + min(curr[j], curr[j + 1]);
                }

                curr = prev;
            }
        }

        return curr[0];
    }
};