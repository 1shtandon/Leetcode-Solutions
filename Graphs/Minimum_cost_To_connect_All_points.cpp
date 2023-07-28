class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();

        // the minimum spanning tree sum is the answer to this problem, so using prim's algo

        // adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int sum = 0;
        // {wt , node}
        pq.push({0, 0});

        vector<bool> vis(n, false);

        while (!pq.empty())
        {
            int currDist = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            if (vis[curr])
            {
                continue;
            }

            vis[curr] = true;
            sum += currDist;

            for (auto it : adj[curr])
            {
                int node = it.first;
                int wt = it.second;

                if (!vis[node])
                {
                    pq.push({wt, node});
                }
            }
        }

        return sum;
    }
};