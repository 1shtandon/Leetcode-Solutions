/*
Approach :

1. For every index i, we need to find the average of the subarray nums[0..i].
2. The maximum of the averages of all subarrays is the answer.
3. As we can always normalize the array towards the average.

Time Complexity : O(N)
Space Complexity : O(1)
*/
class Solution
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        int res = nums[0];
        long long total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
            int avg = ceil((double)total / (i + 1));
            res = max(res, avg);
        }
        return res;
    }
};