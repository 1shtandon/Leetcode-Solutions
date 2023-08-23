class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());

        vector<int> dp(n, 1);

        int res = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};

// Time limit exceeded
// so we try O(nlogn) solution

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {

        int n = envelopes.size();


        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b)
            {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0]; });

        vector<int> lis;


        // O(nlogn) solution using binary search

        for (int i = 0; i < n; i++)
        {
            int env = envelopes[i][1];

            int idx = lower_bound(lis.begin() , lis.end() , env) - lis.begin();

            if (idx >= lis.size())
                lis.push_back(env);
            
            else
                lis[idx] = env;
        }

        return lis.size();
    }
};