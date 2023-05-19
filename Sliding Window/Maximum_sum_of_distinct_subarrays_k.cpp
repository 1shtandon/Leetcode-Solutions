// Simple sliding window approach

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        long long res = 0;
        unordered_map<long long, int> mp;

        long long left = 0, right = 0, curr = 0;

        while (right < n)
        {
            if (mp[nums[right]] == 0)
            {
                curr += nums[right];
                mp[nums[right]]++;
                right++;
            }
            else
            {
                mp[nums[left]]--;
                curr -= nums[left];
                left++;
            }
            if (right - left == k)
            {
                res = max(res, curr);
                mp[nums[left]]--;
                curr -= nums[left];
                left++;
            }
        }

        return res;
    }
};