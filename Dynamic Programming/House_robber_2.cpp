class Solution
{
public:
    int robbing(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        int case1 = nums[0], case2 = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            // either select prev only or this number plus prev->prev . so we need to find the max of these two conditions
            dp[i] = max(nums[i] + case1, case2);
            case1 = case2;
            case2 = dp[i];
        }
        return dp[dp.size() - 1];
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        else if (n == 2)
            return max(nums[0], nums[1]);

        vector<int> temp1(n - 1), temp2(n - 1);
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }
        return max(robbing(temp1), robbing(temp2));
    }
};