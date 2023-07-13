class Solution
{
public:
    bool dfs(int node, vector<vector<int>> adj, vector<bool> &vis, vector<bool> &pathVis, vector<bool> &check)
    {
        vis[node] = true;
        pathVis[node] = true;

        for (auto neighbour : adj[node])
        {
            // if not visited then recursion
            if (!vis[neighbour])
            {
                if (dfs(neighbour, adj, vis, pathVis, check))
                {
                    check[node] = false;
                    return true;
                }
            }

            // if visited and pathvisited both then it means a cycle
            else if (pathVis[neighbour])
            {
                check[node] = false;
                return true;
            }
        }

        // backtracking for a different path
        pathVis[node] = false;

        check[node] = true;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int V = graph.size();
        // using cycle detection approach to find safe nodes
        // any node which is part of a cycle or can reach a cycle is not a safe node

        vector<int> ans;

        vector<bool> vis(V, false);
        vector<bool> pathVis(V, false);
        vector<bool> check(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, graph, vis, pathVis, check);
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (check[i])
                ans.push_back(i);
        }

        return ans;
    }
};