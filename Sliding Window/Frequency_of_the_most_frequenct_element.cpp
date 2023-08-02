class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        // first sort the array and then sliding window can be used to find if for any index, all before it can be made equal to it in k operations at most. the window of max size is the answer.

        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long sum = 0, res = 0, left = 0, right = 0;

        while (right < n)
        {
            sum += nums[right];

            while (((right - left + 1) * nums[right]) - sum > k)
            {
                sum -= nums[left];
                left++;
            }

            res = max(res, right - left + 1);
            right++;
        }

        return res;
    }
};