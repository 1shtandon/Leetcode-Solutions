class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1 and nums[0] < target)
            return 0;

        int minLength = INT_MAX, windowSum = 0;
        int left = 0, right = 0;

        while (right < n)
        {
            windowSum += nums[right];

            while (windowSum >= target)
            {
                minLength = min(right - left + 1, minLength);
                windowSum -= nums[left];
                left++;
            }

            right++;
        }

        return (minLength == INT_MAX) ? 0 : minLength;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)