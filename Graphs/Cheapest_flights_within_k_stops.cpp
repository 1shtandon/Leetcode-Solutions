class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        //priority queue wont work here as it will give shortest path but might not follow k stops and stop other paths that can reach in k stops but have more weight

        // making adjacency list to store  {weight, stops}
        vector<pair<int, int>> adj[n];

        for (auto it : flights)
        {
            int u = it[0], v = it[1], wt = it[2];

            adj[u].push_back({v, wt});
        }

        // queue to store {stops , {node, weight}}
        queue<pair<int, pair<int, int>>> q;

        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int weight = q.front().second.second;
            q.pop();

            if (stops > k)
                continue;

            for (auto it : adj[node])
            {
                int neighbour = it.first;
                int wt = it.second;

                if (weight + wt < dist[neighbour])
                {
                    dist[neighbour] = weight + wt;
                    q.push({stops + 1, {neighbour, dist[neighbour]}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};