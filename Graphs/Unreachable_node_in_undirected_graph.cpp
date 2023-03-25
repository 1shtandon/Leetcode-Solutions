class Solution
{
private:
    void dfs(long long node, vector<long long> adjList[], vector<bool> &visited, long long &nodesInComponent)
    {
        visited[node] = true;
        nodesInComponent++;

        for (auto &it : adjList[node])
        {
            if (!visited[it])
            {
                dfs(it, adjList, visited, nodesInComponent);
            }
        }
    }

public:
    long long countPairs(long long n, vector<vector<long long>> &edges)
    {
        long long totalUnreachableNodes = 0, remainingNodes = n;
        vector<long long> adjList[n];
        vector<bool> visited(n, false);

        // generating adjacency list
        for (auto &edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        for (long long i = 0; i < n; i++)
        {
            long long nodesInComponent = 0;
            if (!visited[i])
            {
                dfs(i, adjList, visited, nodesInComponent);
                totalUnreachableNodes += (remainingNodes - nodesInComponent) * nodesInComponent;
                remainingNodes -= nodesInComponent;
            }
        }

        return totalUnreachableNodes;
    }
};