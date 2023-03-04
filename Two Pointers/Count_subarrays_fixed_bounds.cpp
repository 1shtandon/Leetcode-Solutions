/*
Approach: Two Pointers

1. We will use two pointers to keep track of the min and max element in the current subarray.
2. If the current element is in the range of minK and maxK, then we will update the minIdx and maxIdx.
3. If the current element is not in the range of minK and maxK, then we will reset the minIdx and maxIdx to -1.
4. We will also update the leftIdx to the current index.
5. Now, we will calculate the number of subarrays which can be formed using the current element as the max element.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int n = nums.size();
        long long res = 0;
        int leftIdx = -1, minIdx = -1, maxIdx = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= minK and nums[i] <= maxK)
            {
                minIdx = (nums[i] == minK) ? i : minIdx;
                maxIdx = (nums[i] == maxK) ? i : maxIdx;

                res += max(0, min(minIdx, maxIdx) - leftIdx);
            }
            else
            {
                leftIdx = i;
                minIdx = -1;
                maxIdx = -1;
            }
        }
        return res;
    }
};