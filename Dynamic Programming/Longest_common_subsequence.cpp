class Solution
{
public:
    // int fun(int i , int j, string &s , string &t , vector<vector<int>> &dp)
    // {
    //     if(i < 0 or j < 0)
    //         return 0;

    //     if(dp[i][j] != -1)
    //         return dp[i][j];

    //     if(s[i] == t[j])
    //         return dp[i][j] = 1 + fun(i - 1, j - 1, s, t , dp);

    //     return dp[i][j] = max(fun(i - 1, j , s, t , dp) , fun(i , j - 1 , s , t , dp));
    // }

    int longestCommonSubsequence(string s, string t)
    {
        int n = s.length(), m = t.length();

        // vector<vector<int>> dp(n + 1, vector<int> (m + 1 , 0));

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        if (n == 0 or m == 0)
            return 0;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 or j == 0)
                {
                    curr[j] = 0;
                }
                else if (s[i - 1] == t[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                else
                {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};