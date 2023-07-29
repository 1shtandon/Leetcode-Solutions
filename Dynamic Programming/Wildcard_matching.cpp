class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.length(), m = p.length();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // base case :
        // if s and p both finished , then true
        // if only p finished then false
        // in only s finished, then p must have all * to count as empty, then true else false;

        dp[0][0] = true;

        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = false;
        }

        for (int j = 1; j <= m; j++)
        {
            bool flag = true;
            for (int k = 1; k <= j; k++)
                if (p[k - 1] != '*')
                {
                    flag = false;
                    break;
                }

            dp[0][j] = flag;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // if matched, we move both, or a ?
                if ((s[i - 1] == p[j - 1]) or p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                // else for * make recursion of taking it or not
                else if (p[j - 1] == '*')
                {
                    int not_take = dp[i - 1][j];
                    int take = dp[i][j - 1];

                    dp[i][j] = take or not_take;
                }

                else
                {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};