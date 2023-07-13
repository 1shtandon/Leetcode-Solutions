class Solution
{
public:
    bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &pathVis)
    {
        vis[node] = true;
        pathVis[node] = true;

        for (auto neighbour : adj[node])
        {
            // if not visited then recursion
            if (!vis[neighbour])
            {
                if (dfs(neighbour, adj, vis, pathVis))
                    return true;
            }

            // if visited and pathvisited both then it means a cycle
            else if (pathVis[neighbour])
                return true;
        }

        // backtracking for a different path
        pathVis[node] = false;

        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {

        vector<bool> vis(V, false);
        vector<bool> pathVis(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, pathVis))
                    return true;
            }
        }

        return false;
    }
};

// Time Complexity: O(V + E)
// Space Complexity: O(V) + O(V)