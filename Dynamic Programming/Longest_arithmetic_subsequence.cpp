class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        vector<unordered_map<int , int>> dp(n);
        int res = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                int diff = nums[i] - nums[j];

                if(dp[j].find(diff) != dp[j].end())
                    dp[i][diff] = max(dp[i][diff] , 1 + dp[j][diff]);
                
                else
                    dp[i][diff] = 2;
                // cout << dp[i][diff] << " ";
                res = max(res , dp[i][diff]);
            }
        }

        return res;
    }
};