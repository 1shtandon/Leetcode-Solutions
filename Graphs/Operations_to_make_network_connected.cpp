class Solution
{
private:
    void dfs(int node, vector<int> adjList[], vector<bool> &visited)
    {
        visited[node] = true;

        for (auto &it : adjList[node])
        {
            if (!visited[it])
            {
                dfs(it, adjList, visited);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int wires = connections.size();
        if (wires < n - 1)
            return -1;

        vector<int> adjList[n];
        vector<bool> visited(n, false);

        // generating adjacency list
        for (auto &connection : connections)
        {
            adjList[connection[0]].push_back(connection[1]);
            adjList[connection[1]].push_back(connection[0]);
        }

        int numberOfComponents = 0;
        // applying dfs on the graph to find total number of isolated computer network components

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                numberOfComponents++;
                dfs(i , adjList , visited);
            }
        }

        return numberOfComponents - 1;
    }
};