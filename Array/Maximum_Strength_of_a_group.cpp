// dont follow this approach pls T_T

class Solution
{
public:
    long long maxStrength(vector<int> &nums)
    {
        long long res = 1;
        long long negs = 0, zeros = 0, minNeg = INT_MIN;

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                negs++;
                minNeg = max(minNeg, (long long)nums[i]);
            }
            if (nums[i] == 0)
            {
                zeros++;
                continue;
            }
            res = (long long)(res * nums[i]);
        }
        if (zeros == n or (n >= 2 and negs == 1 and zeros == n - 1))
        {
            return 0;
        }

        if (negs == 1 and n == 1)
        {
            return nums[0];
        }

        if (negs % 2 == 0)
        {
            return res;
        }
        else
        {
            return res / minNeg;
        }
    }
};