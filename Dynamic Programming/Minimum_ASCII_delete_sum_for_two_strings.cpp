class Solution {
public:

    // int fun(int i , int j , string &s , string &t , vector<vector<int>> &dp)
    // {
    //     // both strings get empty
    //     if(i < 0 and j < 0)
    //         return 0;

    //     if(i < 0 and j >= 0)
    //         return t[j] + fun(i , j - 1 , s , t, dp);
        
    //     if(j < 0 and i >= 0)
    //         return s[i] + fun(i - 1, j , s , t, dp);

    //     if(dp[i][j] != -1)
    //         return dp[i][j];

    //     // no need to delete
    //     if(s[i] == t[j])        
    //         return dp[i][j] = fun(i - 1, j - 1, s , t , dp);

    //     return dp[i][j] = min(s[i] + fun(i - 1 , j , s , t , dp) , t[j] + fun(i , j - 1 , s , t , dp));
    // }

    int minimumDeleteSum(string s, string t) {
        int n = s.length() , m = t.length();
        // vector<vector<int>> dp(n + 1 , vector<int> (m + 1 , 0));

        // space optimization
        vector<int> prev(m + 1 , 0);
        vector<int> curr(m + 1 , 0);

        // for(int i = 1; i <= n; i++)
        // {
        //     dp[i][0] = s[i - 1] + dp[i - 1][0];
        // }

        for(int j = 1; j <= m; j++)
        {
            prev[j] = t[j - 1] + prev[j - 1];
        }

        for(int i = 1; i <= n; i++)
        {
            curr[0] = s[i - 1] + prev[0];
            for(int j = 1; j <= m; j++)
            {
                if(s[i - 1] == t[j - 1])
                    curr[j] =  prev[j - 1];
                
                else
                    curr[j] = min(s[i - 1] + prev[j] , t[j - 1] + curr[j - 1]);
            }

            prev = curr;
        }

        return prev[m];
    }
};