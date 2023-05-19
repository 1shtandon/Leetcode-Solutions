class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int n = nums.size();
        int res = 0, left = 0, right = 0;
        while (right < n)
        {
            if (nums[right] == 1)
            {
                res = max(res, right - left + 1);
                right++;
            }
            else
            {
                right++;
                left = right;
            }
        }

        return res;
    }
};