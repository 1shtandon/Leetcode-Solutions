class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1] + 1;
            // for every i, we check if s[j-1 .. i-1] is present in the dictionary
            // if it is present, then assign min of existing dp[i] and dp[j-1], such that dp[j-1] is
            //  the minimum number of extra characters required to make s[0 .. j-1] present in the dictionary
            for (int j = i; j >= 1; j--)
            {
                if (dict.count(s.substr(j - 1, i - j + 1)))
                {
                    dp[i] = min(dp[i], dp[j - 1]);
                }
            }
        }
        return dp[n];
    }
};