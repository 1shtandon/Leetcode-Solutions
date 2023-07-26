class Solution
{
public:
    vector<int> dijsktra(int n, int source, vector<pair<int, int>> adj[])
    {
        vector<int> dist(n, 1e9);
        dist[source] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, source});

        while (!pq.empty())
        {
            int curr = pq.top().second;
            int currDist = pq.top().first;
            pq.pop();

            for (auto it : adj[curr])
            {
                int node = it.first;
                int wt = it.second;

                if (currDist + wt < dist[node])
                {
                    dist[node] = currDist + wt;
                    pq.push({dist[node], node});
                }
            }
        }

        return dist;
    }

    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        // applying dijsktra on every node, for tc: O(n * e * logn) , considering better than floyd warshall as genreally graph is not completely dense
        vector<vector<int>> dp(n, vector<int>(n));

        // also converting to bidirectional, as not given in input
        vector<pair<int, int>> adj[n];

        for (auto edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        // applying dijstra on every node
        for (int i = 0; i < n; i++)
        {
            vector<int> dist = dijsktra(n, i, adj);

            dp[i] = dist;
        }

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {
                cout << dp[i][j] << " ";
            }

            cout << endl;
        }

        int k = INT_MAX, city = 0;
        for (int i = 0; i < n; i++)
        {
            int cities = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j and dp[i][j] <= distanceThreshold)
                {
                    cities++;
                }
            }

            if (k >= cities)
            {
                city = i;
                k = cities;
            }
        }

        return city;
    }
};