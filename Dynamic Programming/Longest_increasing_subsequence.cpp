class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        /*
            LIS at index i can be:
                * 1 + max(LIS(j)) where 0 < j < i and nums[i] > nums[j]
                * 1 if we cant find such j

            Now the result if max of all LIS, so we use an array
        */
        int n = nums.size();
        vector<int> LIS(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        return *max_element(LIS.begin(), LIS.end());
    }
};