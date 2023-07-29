class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        // common should be taken once (longest common subsequence)
        // length of res will be n + m - len(lcs)
        int n = str1.length(), m = str2.length();
        string ans = "";

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 or j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // now building ans
        // if same char then count once, else take char wise out from either strings and add to ans
        int i = n, j = m;

        while (i > 0 and j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                ans += str1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                // remove diagonal one and move up, add the one that goes out after moving in direction and follow the more contributing path
                ans += str1[i - 1];
                i--;
            }
            else
            {
                ans += str2[j - 1];
                j--;
            }
        }

        // now if any string remaining, add to ans
        while (i > 0)
        {
            ans += str1[i - 1];
            i--;
        }
        while (j > 0)
        {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};