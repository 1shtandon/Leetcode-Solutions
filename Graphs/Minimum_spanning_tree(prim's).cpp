class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // adjacency list is already given, also just sum is askde, so dont need parent in the pq
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<bool> vis(V, false);

        int sum = 0;
        // {wt , node}
        pq.push({0, 0});

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
                int node = it[0];
                int wt = it[1];

                if (!vis[node])
                {
                    pq.push({wt, node});
                }
            }
        }

        return sum;
    }
};


/*
this is actually a greedy approach, its time complexity being O(E * logE) and space beign O(E)
*/