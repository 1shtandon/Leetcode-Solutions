// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
// Return the number of nice sub-arrays.

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> oddIndices;
        oddIndices.push_back(-1);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2)
                oddIndices.push_back(i);
        }

        oddIndices.push_back(n);

        int res = 0;
        for (int i = 1; i + k < oddIndices.size(); i++)
        {
            res += (oddIndices[i] - oddIndices[i - 1]) * (oddIndices[i + k] - oddIndices[i + k - 1]);
        }

        return res;
    }
};