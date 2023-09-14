class Solution
{
public:
    // answer is permutation of 2n objects ,and half of those are invalid for each pair

    int countOrders(int n)
    {
        long long int mod = 1e9 + 7;
        long long int ans = 1;

        for (int i = 1; i <= n; i++)
        {
            ans = (ans * (2 * i - 1) * i) % mod;
        }


        return ans;

    }
};