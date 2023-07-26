class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        // n-1 iterations of relaxation on distance vector
        vector<int> dist(n, 1e9);
        dist[0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (auto edge : edges)
            {
                int u = edge[0], v = edge[1], wt = edge[2];

                if (dist[u] + wt < dist[v])
                {
                    // if at the last iteration too the distance is getting shorter, it means a negative weight cycle exists
                    if (i == n - 1)
                        return 1;
                    dist[v] = dist[u] + wt;
                }
            }
        }

        return 0;
    }
};

// TC : O(V *E)
// SC : O(V)