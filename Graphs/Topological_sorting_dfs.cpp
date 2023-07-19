class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &s)
    {
        visited[node] = true;

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
                dfs(neighbour, adj, visited, s);
        }

        // when dfs calls for this node ends, push in stack
        s.push(node);
    }

    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        stack<int> s;
        vector<int> res;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, s);
            }
        }

        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }

        return res;
    }
};