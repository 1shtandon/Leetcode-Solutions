class Solution
{
public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        queue<int> q;
        vector<int> indegree(V, 0);
        vector<int> topoSort;

        // finding indegree of all nodes
        for (int i = 0; i < V; i++)
        {
            for (auto neighbour : adj[i])
            {
                indegree[neighbour]++;
            }
        }

        // applying kahn's algorithm
        /*
        1. put all nodes with no incoming edges in queue
        2. one by one pop queue front and decrement indegree of all its neighbour by 1.
        3. if any of its indegree now becomes 0, push in queue, else take next element from queue.
        */

        for (int i = 0; i < V; i++)
        {
            if (!indegree[i])
                q.push(i);
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            topoSort.push_back(curr);

            for (auto neighbour : adj[curr])
            {
                indegree[neighbour]--;

                if (!indegree[neighbour])
                {
                    q.push(neighbour);
                }
            }
        }

        return topoSort;
    }
};