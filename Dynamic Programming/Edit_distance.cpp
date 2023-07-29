class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length(), m = word2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // for base case, consider when s1 is empty , it needs s2.length operation to insert and make s1 as s2
        // same if s2 is empty , needs s1.length operation to delete every char and make s2

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i <= m; i++)
        {
            dp[0][i] = i;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // if matched then 0 ops, and move
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // 3 cases :
                    //  insertion  : insert in s1 , so i dont move and j moves
                    //  delete : i becomes less and j remains same
                    // replace : both index moves as they match

                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
            }
        }

        return dp[n][m];
    }
};