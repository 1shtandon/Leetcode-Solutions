class Solution
{
public:
    int recursion(int i, int j, vector<int> &a, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int maxi = INT_MIN;
        // iterating for last balloon to burst
        for (int ind = i; ind <= j; ind++)
        {
            int cost = (a[i - 1] * a[ind] * a[j + 1]) + recursion(i, ind - 1, a, dp) + recursion(ind + 1, j, a, dp);
            maxi = max(maxi, cost);
        }

        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return recursion(1, n, nums, dp);
    }
};


/*
Tabulation method
*/

class Solution
{
public:

    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i > j)
                    continue;

                int maxi = INT_MIN;
                // iterating for last balloon to burst
                for (int ind = i; ind <= j; ind++)
                {
                    int cost = (nums[i - 1] * nums[ind] * nums[j + 1]) + dp[i][ind - 1] + dp[ind + 1][j];
                    maxi = max(maxi, cost);
                }

                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }
};