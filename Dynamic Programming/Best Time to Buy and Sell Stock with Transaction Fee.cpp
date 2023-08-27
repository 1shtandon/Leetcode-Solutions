class Solution
{
public:
    // int fun(int i , bool buy ,int &n , int &fee , vector<int> &prices , vector<vector<int>> &dp)
    // {
    //     if(i == n)
    //         return 0;

    //     if(dp[i][buy] != -1)
    //         return dp[i][buy];

    //     int res;
    //     if(buy)
    //     {
    //         res = max(-prices[i] + fun(i + 1 , false , n , fee , prices , dp) , fun(i + 1 , true , n , fee , prices , dp));
    //     }
    //     else
    //         res = max(prices[i] - fee + fun(i + 1 , true , n , fee , prices , dp) , fun(i + 1, false , n , fee , prices , dp));

    //     return dp[i][buy] = res;
    // }

    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();

        // vector<vector<int>> dp(n + 1, vector<int>(2 , 0));

        // space optimization
        int prev1 = 0, prev2 = 0;
        int curr1 = 0, curr2 = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                {
                    curr2 = max(-prices[i] + prev1, prev2);
                }
                else
                {
                    curr1 = max(prices[i] - fee + prev2, prev1);
                }
            }
            prev1 = curr1, prev2 = curr2;
        }

        return prev2;
    }
};