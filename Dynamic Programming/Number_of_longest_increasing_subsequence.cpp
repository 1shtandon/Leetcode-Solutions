class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 0)
            return 0;
        
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        
        int max_len = 1;
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
                if(nums[i] > nums[j])
                {
                    if(dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if(dp[j] + 1 == dp[i])
                        count[i] += count[j];
                }
            
            max_len = max(max_len, dp[i]);
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++)
            if(dp[i] == max_len)
                ans += count[i];
        
        return ans;
    }
};