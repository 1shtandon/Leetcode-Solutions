class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> res(n, -1);

        if (k == 0)
            return nums;

        if (n < 2 * k + 1)
            return res;

        int startIdx = k;
        int ptr1 = 0, ptr2 = 2 * k;
        long long sum = 0;

        for (int i = ptr1; i <= ptr2; i++)
        {
            sum += nums[i];
        }

        while (startIdx <= n - k - 1 and ptr2 < n)
        {
            res[startIdx] = (long long)(sum / (2 * k + 1));

            sum -= nums[ptr1];
            ptr1++;
            ptr2++;
            if (ptr2 == n)
            {
                break;
            }
            sum += nums[ptr2];
            startIdx++;
        }

        return res;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)