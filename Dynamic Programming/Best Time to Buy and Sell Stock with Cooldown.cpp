class Solution
{
public:
    // int fun(int i , int &n , bool buy , vector<int> &prices , vector<vector<int>> &dp)
    // {
    //     if(i >= n)
    //         return 0;

    //     if(dp[i][buy] != -1)
    //         return dp[i][buy];

    //     int res;
    //     if(buy)
    //     {
    //         int buys = -prices[i] + fun(i + 1 , n , false , prices , dp);
    //         int not_buys = fun(i + 1 , n , true , prices , dp);

    //         res = max(buys , not_buys);
    //     }
    //     else
    //     {
    //         // cooldown
    //         int sells = prices[i] + fun(i + 2 , n , true , prices , dp);
    //         int not_sells = fun(i + 1 , n , false , prices , dp);

    //         res = max(sells , not_sells);
    //     }

    //     dp[i][buy] = res;
    //     return res;
    // }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
            return 0;

        // vector<vector<int>> dp(n + 2, vector<int>(2));

        // space optimization
        vector<int> supPrev(2);
        vector<int> prev(2);
        vector<int> curr(2);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {

                if (buy)
                    curr[buy] = max(-prices[i] + prev[0], prev[1]);

                else
                    curr[buy] = max(prices[i] + supPrev[1], prev[0]);
            }
            supPrev = prev;
            prev = curr;
        }

        return curr[1];
    }
};