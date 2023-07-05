class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = 0;
        // variable size sliding window approach
        // maintain a sliding window with at most 1 zero, which could be removed eventually for subarray with all 1s
        
        int res = INT_MIN, zero = 0;

        while (right < n)
        {
            if (nums[right] == 0)
            {
                zero++;
            }

            if (zero > 1)
            {
                res = max(res, right - left - 1);
                while (zero > 1)
                {
                    if (nums[left] == 0)
                    {
                        zero--;
                    }

                    left++;
                }
            }

            right++;
        }
        res = max(res, right - left - 1);
        return res == INT_MIN ? 0 : res;
    }
};