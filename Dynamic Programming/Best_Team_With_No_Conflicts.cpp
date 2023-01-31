/*
Approach: Dynamic Programming
1. Sort the players on the basis of their ages.
2. Create a dp array of size n and initialize it with the scores of the players.
3. For each player, check if the score of the player is greater than or equal to the score of the previous player.
4. If yes, then add the score of the current player to the dp value of the previous player.
5. Return the maximum value in the dp array.

Time Complexity: O(n^2)
Space Complexity: O(n)
*/

class Solution
{
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = scores.size();
        vector<pair<int, int>> v;
        // store ages and scores in a vector of pairs so as to sort
        for (int i = 0; i < n; i++)
        {
            v.push_back({ages[i], scores[i]});
        }
        // sorting on the basis of ages
        sort(v.begin(), v.end());
        vector<int> dp(n, 0);
        dp[0] = v[0].second;
        for (int i = 1; i < n; i++)
        {
            dp[i] = v[i].second;
            for (int j = 0; j < i; j++)
            {
                if (v[i].second >= v[j].second)
                {
                    dp[i] = max(dp[i], dp[j] + v[i].second);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};