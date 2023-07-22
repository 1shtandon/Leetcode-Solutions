class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // making adjacency list
        vector<pair<int, int>> adj[n + 1];

        for (int i = 0; i < m; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 1});

        vector<int> dist(n + 1, 1e9);
        dist[1] = 0;

        vector<int> parent(n + 1);
        // initially the node is itself the parent
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }

        // applying dikjstra's algo while also keeping track of parent
        while (!pq.empty())
        {
            int curr = pq.top().second;
            int currDist = pq.top().first;
            pq.pop();

            for (auto it : adj[curr])
            {
                int node = it.first;
                int weight = it.second;

                // here update distance and parent where it comes from
                if (currDist + weight < dist[node])
                {
                    dist[node] = currDist + weight;
                    parent[node] = curr;
                    pq.push({dist[node], node});
                }
            }
        }

        // if n is unreachable return -1
        if (dist[n] == 1e9)
            return {-1};

        // now building path by traversing from nth node backwards using parent
        vector<int> path;
        int ptr = n;

        // source is its parent itself, so stopping condition
        while (parent[ptr] != ptr)
        {
            path.push_back(ptr);

            // going backwards
            ptr = parent[ptr];
        }
        path.push_back(1);

        // reversing and return
        reverse(path.begin(), path.end());

        return path;
    }
};