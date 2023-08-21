class Solution
{
public:
    // int fun(int i , int j , string &word1 , string &word2 , vector<vector<int>> &dp)
    // {
    //     if(i < 0 and j < 0)
    //         return 0;

    //     if(i < 0 and j >= 0)
    //         return j + 1;

    //     if(j < 0 and i >= 0)
    //         return i + 1;

    //     if(dp[i][j] != -1)
    //         return dp[i][j];

    //     if(word1[i] == word2[j])
    //     {
    //         return dp[i][j] = fun(i - 1 , j - 1 , word1 , word2 , dp);
    //     }

    //     int replace = fun(i - 1 , j - 1, word1 , word2 , dp);
    //     int insert = fun(i , j - 1, word1 , word2 , dp);
    //     int delet = fun(i - 1 , j, word1 , word2 , dp);

    //     return dp[i][j] =  1 + min({replace , insert , delet});
    // }

    int minDistance(string word1, string word2)
    {
        int n = word1.length(), m = word2.length();

        if (n == 0)
            return m;
        else if (m == 0)
            return n;

        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

        // space optimization
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        for (int j = 1; j <= m; j++)
        {
            prev[j] = j;
        }

        for (int i = 1; i <= n; i++)
        {
            curr[0] = i;
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    curr[j] = prev[j - 1];

                else
                {
                    curr[j] = 1 + min({curr[j - 1], prev[j], prev[j - 1]});
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};

// TC : O(n*m)
// SC : O(n) or O(m)