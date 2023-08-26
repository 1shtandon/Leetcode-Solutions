class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size() , n = nums2.size();
        // vector<vector<int>> dp(m + 1 , vector<int> (n + 1 , 0));

        vector<int> prev(n + 1 , 0);
        vector<int> curr(n + 1 , 0);

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                // if elements are equal, then count it
                if(nums1[i - 1] == nums2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                // if not then two conditions, move one step from nums1 or nums2
                else
                {
                    curr[j] = max(prev[j] , curr[j - 1]);
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};