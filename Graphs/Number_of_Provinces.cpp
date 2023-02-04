/*
Approach : DFS
1. First convert the adjacency matrix to adjacency list.
2. Then we run a DFS on the adjacency list.
3. Every time we run a DFS, we increment the number of provinces.
4. We return the number of provinces.

Time Complexity : O(n^2)
Space Complexity : O(n)
*/

class Solution
{
private:
    void dfs(int node, vector<int> adjList[], vector<bool> &visited)
    {
        visited[node] = true;
        for(auto &it : adjList[node])
        {
            if(!visited[it])
            {
                dfs(it, adjList , visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int nodes = isConnected.size();
        int numberOfProvince = 0;
        // converting adjacency matrix to adjacency list
        vector<int> adjList[nodes];
        vector<bool> visited(nodes, false);
        for (int i = 0; i < nodes; i++)
        {
            for (j = 0; j < nodes; j++)
            {
                if (i != j and isConnected[i][j] == 1)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        for (int i = 0; i < nodes; i++)
        {
            if (!visited[i])
            {
                numberOfProvince++;
                dfs(i, adjList, visited);
            }
        }

        return numberOfProvince;
    }
};