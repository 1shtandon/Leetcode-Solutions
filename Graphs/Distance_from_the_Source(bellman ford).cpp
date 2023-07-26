class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V, 1e8);
        dist[S] = 0;

        for (int i = 0; i < V; i++)
        {
            for (auto edge : edges)
            {
                int u = edge[0], v = edge[1], wt = edge[2];

                if (dist[u] != 1e8 and dist[u] + wt < dist[v])
                {
                    if (i == V - 1)
                        return {-1};
                    
                    dist[v] = dist[u] + wt;
                }
            }
        }

        return dist;
    }
};