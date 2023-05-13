/*
Approach : Dynamic Programming
For computing the ways for length x, we need to know the ways for length x - zero and x - one
as there are two options for each length, either we can add  zero 0s or one 1s
starting with dp[0] = 1 as there is only 1 way of making string of length 0
*/

class Solution
{
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        int total = 0;
        int mod = 1e9 + 7;
        vector<int> dp = {1};
        for (int i = 1; i <= high; i++)
        {
            dp.push_back(0);

            if (i - zero >= 0)
            {
                dp[i] = (dp[i] + dp[i - zero]) % mod;
            }
            if (i - one >= 0)
            {
                dp[i] = (dp[i] + dp[i - one]) % mod;
            }
            if (i >= low and i <= high)
                total = (total + dp[i]) % mod;
        }

        return total;
    }
};