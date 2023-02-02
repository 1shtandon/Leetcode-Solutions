/*
Approach : Two Pointers
1. Sort the array.
2. Fix the first element and then use two pointers to find the other two elements.
3. If the sum is less than 0, then we need to increase the sum, so we move the left pointer.
4. If the sum is greater than 0, then we need to decrease the sum, so we move the right pointer.
5. Use a set of vectors to store only unique triplets.
Time Complexity : O(n^2)
Space Complexity : O(n)
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        set<vector<int>> st;
        if (nums[0] > 0)
            return res;
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 and nums[i - 1] == nums[i])
                continue;
            int currNum = nums[i];
            int start = i + 1, end = n - 1;
            while (start < end)
            {
                int sum = currNum + nums[start] + nums[end];
                if (sum == 0)
                    st.insert({currNum, nums[start], nums[end]});

                if (sum <= 0)
                    start++;
                else
                    end--;
            }
        }
        for (auto &x : st)
            res.push_back(x);
        return res;
    }
};