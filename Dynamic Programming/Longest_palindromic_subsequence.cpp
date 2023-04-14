class Solution
{
public:
    // recursive approach
    int helper(string &s, int start, int end)
    {
        if (start > end)
            return 0;
        else if (start == end)
            return 1;
        else if (s[start] == s[end])
            return 2 + helper(s, start + 1, end - 1);
        else
            return max(helper(s, start + 1, end), helper(s, start, end - 1));
    }

    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // for length 1 to n , considering all strings and computing dp matrix

        for (int length = 1; length <= n; length++)
        {
            // all starting points for considered length
            for (int start = 0; start <= n - length; start++)
            {
                int end = start + length - 1;
                if (length == 1)
                {
                    dp[start][end] = 1;
                    continue;
                }
                else if (s[start] == s[end])
                {
                    dp[start][end] = 2 + dp[start + 1][end - 1];
                }
                else
                {
                    dp[start][end] = max(dp[start + 1][end], dp[start][end - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};