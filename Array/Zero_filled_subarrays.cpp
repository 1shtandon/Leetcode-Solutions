class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> zeros(n, 0);
        if (nums[0] == 0)
            zeros[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == 0)
                zeros[i] = zeros[i - 1] + 1;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                ans += zeros[i];
        }
        return ans;
    }
};


