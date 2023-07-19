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

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // approach : if there is a cycle in the graph then we can't complete all the courses

        vector<int> adj[numCourses];
        vector<bool> visited(numCourses, false);
        vector<bool> pathVisited(numCourses, false);

        // making adjacency list
        for (auto &edge : prerequisites)
        {
            adj[edge[1]].push_back(edge[0]);
        }

        // checking for cycle
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                // if cycle is present then return false
                if (dfs(i, adj, visited, pathVisited))
                    return false;
            }
        }

        return true;
    }
};

// Time Complexity: O(V + E)
// Space Complexity: O(V) + O(V)

/*
BFS Approach using kahn's algorithm

1. we know topo sort is only for DAGs, so if we apply it on a cyclic graph, it wont generate topo sort of n vertices.
2. this is how we can check if there is a cycle or not.

*/

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> adj[numCourses];
        int topoSortSize;
        queue<int> q;
        vector<int> indegree(numCourses, 0);

        // making adjacency list
        for (auto &edge : prerequisites)
        {
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            topoSortSize++;

            for (auto neighbours : adj[curr])
            {
                indegree[neighbours]--;

                if (indegree[neighbours] == 0)
                    q.push(neighbours);
            }
        }

        return topoSortSize == numCourses;
    }
};