class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto &road : roads)
        {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }
        // amonge all the nodes connected to 1 , just find the least one and return it
        int res = INT_MAX;
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto &edge : graph[node])
            {
                res = min(res, edge.second);
                if (!visited[edge.first])
                {
                    visited[edge.first] = true;
                    q.push(edge.first);
                }
            }
        }
        return res;
    }
};