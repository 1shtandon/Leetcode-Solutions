class Solution
{
public:
    // int fun(int i , int j , string &s , vector<vector<int>> &dp)
    // {
    //     if(i >= j)
    //         return 0;

    //     if(dp[i][j] != -1)
    //         return dp[i][j];

    //     if(s[i] == s[j])
    //         return dp[i][j] = fun(i + 1, j - 1, s, dp);

    //     return dp[i][j] = 1 + min(fun(i + 1 , j , s , dp) , fun(i , j - 1 , s , dp));
    // }

    int minInsertions(string s)
    {
        int n = s.length();

        if (n == 1)
            return 0;

        // vector<vector<int>> dp(n , vector<int> (n , 0));
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (i >= j)
                    continue;

                if (s[i] == s[j])
                {
                    curr[j] = prev[j - 1];
                }
                else
                {
                    curr[j] = 1 + min(curr[j - 1], prev[j]);
                }
            }

            prev = curr;
        }

        return curr[n - 1];
    }
};