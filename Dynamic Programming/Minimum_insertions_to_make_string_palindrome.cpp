/*
Approach : Dynamic Programming

1. We need to find the  number of new insertions to make the string a palindrome.
2. So, if we could count the longest palindromic subsequence that is already present in the string, the rest of the string will be the new insertions.
3. Length of the string - length of the longest palindromic subsequence = number of new insertions.

Time Complexity : O(n^2)
Space Complexity : O(n^2)
*/

class Solution
{
public:
    int minInsertions(string s)
    {
        // we first find the longest palindromic susbequence
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int length = 1; length <= n; length++)
        {
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

        return n - dp[0][n - 1];
    }
};