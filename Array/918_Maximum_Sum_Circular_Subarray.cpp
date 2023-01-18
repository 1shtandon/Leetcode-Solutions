/*
Approach : Kadane's Algorithm
For a circular array, there are two cases in which the maximum subarray sum can occur:
1. The subarray does not wrap around the array. In this case, the result is the same as the 
   Kadane's algorithm for finding the maximum subarray sum.
2. The subarray does wrap around the array. In this case, the result is equal to the total
    sum of the array minus the minimum subarray sum.(If the minimum subarray is in middle then max sum is total - minSum)

Note: If all numbers are negative, then maxSum will be the maximum number in the array. In this case, 
      the result is equal to the maxSum.
Time Complexity: O(n)
Space Complexity: O(1)
*/


class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();
        int arrSum = 0, maxSum = INT_MIN, minSum = INT_MAX, currMax = 0, currMin = 0;
        for (int i = 0; i < n; i++)
        {
            currMax = max(currMax + nums[i], nums[i]);
            maxSum = max(maxSum, currMax);
            currMin = min(currMin + nums[i], nums[i]);
            minSum = min(minSum, currMin);
            arrSum += nums[i];
        }

        if (maxSum > 0)
            return max(maxSum, arrSum - minSum);
        return maxSum;
    }
};