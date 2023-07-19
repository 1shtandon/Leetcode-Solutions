class Solution
{
public:
    void dfs(int node, vector<pair<int, int>> adj[], vector<bool> &visited, stack<int> &s)
    {

        visited[node] = true;

        for (auto it : adj[node])
        {
            if (!visited[it.first])
            {
                dfs(it.first, adj, visited, s);
            }
        }

        s.push(node);
    }

    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // making adjacency list, storing {edge , weight} pair for each node
        vector<pair<int, int>> adj[n];

        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];

            adj[u].push_back({v, wt});
        }

        // applying topological sort using dfs
        stack<int> s;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, s);
            }
        }

        // now taking out elements from stack one by one and relaxing the edges
        // calculating the distance

        vector<int> dist(n, 1e9);

        dist[0] = 0;

        while (!s.empty())
        {
            int curr = s.top();
            s.pop();

            for (auto it : adj[curr])
            {
                int neighbour = it.first;
                int wt = it.second;

                dist[neighbour] = min(dist[neighbour], wt + dist[curr]);
            }
        }

        // if dist still 1e9, it means no connection so convert to -1

        for (int i = 0; i < n; i++)
        {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }

        return dist;
    }
};