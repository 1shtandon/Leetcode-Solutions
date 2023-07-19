/*
Basically we have to return the topological sort of the graph given. So we can apply Kahn's algorithm
*/

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> adj[numCourses];
        vector<int> topoSort;
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

            topoSort.push_back(curr);

            for (auto neighbours : adj[curr])
            {
                indegree[neighbours]--;

                if (!indegree[neighbours])
                    q.push(neighbours);
            }
        }

        if (topoSort.size() != numCourses)
            return {};

        return topoSort;
    }
};