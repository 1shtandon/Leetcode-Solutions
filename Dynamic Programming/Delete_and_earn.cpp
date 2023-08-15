class Solution
{
public:
    // int fun(int idx , vector<int> &sum , vector<int> &dp)
    // {
    //     // base case
    //     if(idx < 0)
    //         return 0;

    //     if(idx == 0)
    //         return dp[0] =  sum[0];

    //     if(dp[idx] != -1)
    //         return dp[idx];

    //     int choose = sum[idx] + fun(idx - 2, sum , dp);
    //     int not_choose = fun(idx - 1, sum , dp);

    //     return dp[idx] = max(choose , not_choose);
    // }

    int deleteAndEarn(vector<int> &nums)
    {
        int n = 10001;

        vector<int> sum(n, 0);
        vector<int> dp(n, 0);

        for (auto &num : nums)
        {
            sum[num] += num;
        }

        dp[0] = sum[0];
        dp[1] = max(sum[1], sum[0]);

        for (int i = 2; i < n; i++)
        {
            int choose = sum[i] + dp[i - 2];
            int not_choose = dp[i - 1];

            dp[i] = max(choose, not_choose);
        }
        return dp[n - 1];
    }
};