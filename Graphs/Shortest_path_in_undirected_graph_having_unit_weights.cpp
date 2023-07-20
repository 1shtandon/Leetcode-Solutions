class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int n, int m, int src)
    {
        vector<int> adj[n];

        // making adjacency list
        for (int i = 0; i < m; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(n, false);

        vector<int> dist(n, -1);

        dist[src] = 0;
        visited[src] = true;
        queue<int> q;

        q.push(src);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto it : adj[curr])
            {
                if (!visited[it])
                {
                    dist[it] = dist[curr] + 1;
                    q.push(it);
                    visited[it] = true;
                }
                else
                {
                    dist[it] = min(dist[it], dist[curr] + 1);
                }
            }
        }

        return dist;
    }
};
