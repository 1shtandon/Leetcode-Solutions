class Solution
{
public:
    // int fun(int i , bool buy , int cap , int &n , vector<int>& prices , vector<vector<vector<int>>> &dp)
    // {
    //     if(i == n or cap == 0)
    //         return 0;

    //     if(dp[i][buy][cap] != -1)
    //         return dp[i][buy][cap];

    //     if(buy)
    //     {
    //         return dp[i][buy][cap] = max(-prices[i] + fun(i + 1 , false , cap , n , prices , dp) , fun(i + 1, true , cap , n , prices , dp));
    //     }

    //     return dp[i][buy][cap] = max(prices[i] + fun(i + 1 , true , cap - 1 , n , prices , dp) , fun(i + 1, false , cap , n , prices , dp));
    // }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 1)
            return 0;

        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2 , vector<int> (3 , 0)));

        // space optimization
        // vector<vector<int>> prev(2, vector<int> (3 , 0));
        // vector<vector<int>> curr(2, vector<int> (3 , 0));

        // space optimization once more
        vector<int> prev1(3, 0);
        vector<int> prev2(3, 0);
        vector<int> curr1(3, 0);
        vector<int> curr2(3, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    if (buy)
                        curr2[cap] = max(-prices[i] + prev1[cap], prev2[cap]);

                    else
                        curr1[cap] = max(prices[i] + prev2[cap - 1], prev1[cap]);
                }
            }

            prev1 = curr1;
            prev2 = curr2;
        }

        return prev2[2];
    }
};