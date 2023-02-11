/*
GFG Problem

Approach : Breadth First Search
1. Since the graph is undirected, we will apply bfs on every connected component
2. We will apply bfs on every connected component and check if there is a cycle in the graph
3. To check cycle, we need to find by traversing through different nodes, if we find a node which is already visited and its parent is not the current node, then it means a cycle is present

Time Complexity : O(V+E)
Space Complexity : O(V)
*/

class Solution
{
private:
    bool isCycleBfs(int start, vector<int> adj[], vector<bool> &vis)
    {
        vis[start] = true;
        // queue to store {node , parent}
        queue<pair<int, int>> q;
        q.push({start, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto &adjNode : adj[node])
            {
                if (!vis[adjNode])
                {
                    vis[adjNode] = true;
                    q.push({adjNode, node});
                }

                // if the neighbour is visited and its parent is some other node, then it means a cycle
                else if (parent != adjNode)
                    return true;
            }
        }

        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V, false);
        // now for every connected component, we apply isCycleBfs
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (isCycleBfs(i, adj, vis))
                    return true;
            }
        }

        return false;
    }
};