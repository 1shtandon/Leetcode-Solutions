class Solution
{
public:
    // int fun(int idx , int &n , unordered_set<string> &st , string &s , vector<int> &dp)
    // {
    //     // base case
    //     if(idx >= n)
    //         return 0;

    //     if(dp[idx] != -1)
    //         return dp[idx];

    //     string str = "";
    //     int res = n;

    //     for(int i = idx; i < n; i++)
    //     {
    //         str.push_back(s[i]);

    //         int currExtra;
    //         if(st.count(str))
    //             currExtra = 0;
    //         else
    //             currExtra = str.length();

    //         int newExtra = fun(i + 1 , n , st , s , dp);

    //         res = min(res , currExtra + newExtra);
    //     }

    //     return dp[idx] = res;
    // }

    int minExtraChar(string s, vector<string> &dictionary)
    {
        int n = s.length();
        unordered_set<string> st;

        for (auto &s : dictionary)
            st.insert(s);

        vector<int> dp(51, n);

        dp[n] = 0;

        for (int idx = n - 1; idx >= 0; idx--)
        {
            string str = "";
            for (int i = idx; i < n; i++)
            {
                str.push_back(s[i]);

                int currExtra = (st.count(str) == 1) ? 0 : str.length();
                int newExtra = dp[i + 1];

                dp[idx] = min(dp[idx], currExtra + newExtra);
            }
        }

        return dp[0];
    }
};
