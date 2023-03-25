/*
Approach: DFS

1. while making adjacency list, consider undirected and with direction
2. For direction , 1 means from parent to child (which is to be reversed)
3. -1 means from child to parent (which is correct) 
*/
class Solution
{
public:
    void dfs(int node, vector<vector<pair<int, int>>> &adjList, vector<bool> &visited, int &pathsToReverse)
    {
        visited[node] = true;

        for (pair<int, int> neighbour : adjList[node])
        {
            if (!visited[neighbour.first])
            {
                if (neighbour.second == 1)
                {
                    pathsToReverse++;
                }
                dfs(neighbour.first, adjList, visited, pathsToReverse);
            }
        }
    }

    int minReorder(int n, vector<vector<int>> &connections)
    {
        int pathsToReverse = 0;
        vector<vector<pair<int, int>>> adjList(n);
        for (auto &connection : connections)
        {
            // direction 1 means from parent to child (which is to be reversed)
            adjList[connection[0]].push_back({connection[1], 1});
            // direction -1 means from child to parent (which is correct)
            adjList[connection[1]].push_back({connection[0], -1});
        }

        vector<bool> visited(n, false);
        dfs(0, adjList, visited, pathsToReverse);

        return pathsToReverse;
    }
};

