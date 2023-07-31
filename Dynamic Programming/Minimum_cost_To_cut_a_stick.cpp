class Solution
{
public:
    int recursion(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;
        // maintaining every possible partition
        for (int ind = i; ind <= j; ind++)
        {
            int cost = (cuts[j + 1] - cuts[i - 1]) + recursion(i, ind - 1, cuts, dp) + recursion(ind + 1, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int> &cuts)
    {
        // if we sort the cuts array, then partitions after cutting can be solved separately
        int sz = cuts.size();

        vector<vector<int>> dp(sz + 1, vector<int>(sz + 1, -1));

        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());

        // now applying recursion
        return recursion(1, sz, cuts, dp);
    }
};

/*
Tabulation solution
*/

class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        // if we sort the cuts array, then partitions after cutting can be solved separately
        int sz = cuts.size();

        vector<vector<int>> dp(sz + 2, vector<int>(sz + 2, 0));

        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());

        for (int i = sz; i >= 1; i--)
        {
            for (int j = 1; j <= sz; j++)
            {
                if (i > j)
                    continue;

                int mini = INT_MAX;

                for (int k = i; k <= j; k++)
                {
                    int cost = (cuts[j + 1] - cuts[i - 1]) + dp[i][k - 1] + dp[k + 1][j];
                    mini = min(mini, cost);
                }
                
                dp[i][j] = mini;
            }
        }

        return dp[1][sz];
    }
};