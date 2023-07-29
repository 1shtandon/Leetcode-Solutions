class Solution
{
public:
    bool canPartition(vector<int> &arr)
    {
        int n = arr.size();
        int k = 0;
        for (auto i : arr)
        {
            k += i;
        }

        if (k % 2 == 1)
            return false;

        k /= 2;

        vector<vector<bool>> dp(n, vector<bool>(k + 1));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        for (int i = 1; i < k + 1; i++)
        {
            dp[0][i] = (arr[0] == i);
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < k + 1; j++)
            {
                bool not_take = dp[i - 1][j];
                bool take = false;
                if (j >= arr[i])
                {
                    take = dp[i - 1][j - arr[i]];
                }
                dp[i][j] = take || not_take;
            }
        }

        return dp[n - 1][k];
    }
};