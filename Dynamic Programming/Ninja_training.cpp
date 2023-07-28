/*
Memoization
*/

int recursion(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{

    // base case
    if (day == 0)
    {
        int maxi = 0;

        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, points[0][i]);
            }
        }

        return maxi;
    }

    if (dp[day][last] != -1)
        return dp[day][last];

    int maxi = 0;

    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int earned = points[day][i] + recursion(day - 1, i, points, dp);

            maxi = max(maxi, earned);
        }
    }

    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{

    vector<vector<int>> dp(n, vector<int>(4, -1));

    return recursion(n - 1, 3, points, dp);
}

/*

Tabulation
*/

int ninjaTraining(int n, vector<vector<int>> &points)
{

    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    //   3 means no task was done on last day
    dp[0][3] = max(max(points[0][0], points[0][1]), points[0][2]);

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int earned = points[day][task] + dp[day - 1][task];
                    maxi = max(maxi, earned);
                }
            }

            dp[day][last] = maxi;
        }
    }

    return return dp[n - 1][3];
}