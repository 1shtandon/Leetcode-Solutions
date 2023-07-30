
/*
    recursive solution
*/
class Solution
{
public:
    int recursion(int ind, int buy, int cap, vector<int> &prices)
    {
        if (ind == prices.size() or cap == 0)
            return 0;

        // if buying is allows, then either buy or not
        if (buy)
        {
            int buy = recursion(ind + 1, 0, cap, prices) - prices[ind];
            int not_buy = recursion(ind + 1, 1, cap, prices);

            return max(buy, not_buy);
        }
        else
        {
            int sell = recursion(ind + 1, 1, cap - 1, prices) + prices[ind];
            int not_sell = recursion(ind + 1, 0, cap, prices);

            return max(sell, not_sell);
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        return recursion(0, 1, 2, prices);
    }
};

/*
    memoization solution
*/
class Solution
{
public:
    int recursion(int n, int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (ind == n or cap == 0)
            return 0;

        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        // if buying is allows, then either buy or not
        if (buy == 1)
        {
            int buy_val = -prices[ind] + recursion(n, ind + 1, 0, cap, prices, dp);
            int not_buy = recursion(n, ind + 1, 1, cap, prices, dp);

            return dp[ind][buy][cap] = max(buy_val, not_buy);
        }

        else
        {
            int sell = recursion(n, ind + 1, 1, cap - 1, prices, dp) + prices[ind];
            int not_sell = recursion(n, ind + 1, 0, cap, prices, dp);

            return dp[ind][buy][cap] = max(sell, not_sell);
        }

        return dp[ind][buy][cap];
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));

        return recursion(n, 0, 1, 2, prices, dp);
    }
};

/*
    tabulation solution
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // base case
        // if no stock, then profit is 0
        // if no capacity, then profit is 0

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    // if buying is allows, then either buy or not
                    if (buy == 1)
                    {
                        int buy_val = -prices[ind] + dp[ind + 1][0][cap];
                        int not_buy = dp[ind + 1][1][cap];

                        dp[ind][buy][cap] = max(buy_val, not_buy);
                    }

                    else
                    {
                        int sell = dp[ind + 1][1][cap - 1] + prices[ind];
                        int not_sell = dp[ind + 1][0][cap];

                        dp[ind][buy][cap] = max(sell, not_sell);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};