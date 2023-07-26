class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        int mod = 1e9 + 7;

        // to store in adj list in form {weight, node}
        vector<vector<pair<int, int>>> adj(n);

        // making adjacency list
        for (int i = 0; i < roads.size(); i++)
        {
            adj[roads[i][0]].push_back({roads[i][2], roads[i][1]});
            adj[roads[i][1]].push_back({roads[i][2], roads[i][0]});
        }

        // to store the distance of each node from the destination
        vector<long long> dist(n, 1e18);

        dist[0] = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        pq.push({0, 0});

        // no of ways to reach the destination
        vector<long long> ways(n, 0);

        ways[0] = 1;

        while (!pq.empty())
        {
            int node = pq.top().second;
            long long d = pq.top().first;
            pq.pop();

            if (d > dist[node])
                continue;

            for (auto it : adj[node])
            {
                int wt = it.first;
                int next = it.second;

                if (dist[next] > dist[node] + wt)
                {
                    dist[next] = dist[node] + wt;
                    pq.push({dist[next], next});
                    ways[next] = ways[node];
                }
                else if (dist[next] == dist[node] + wt)
                {
                    ways[next] = (ways[next] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};
