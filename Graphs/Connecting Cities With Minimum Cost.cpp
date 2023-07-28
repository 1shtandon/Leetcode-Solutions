#include <bits/stdc++.h>
int getMinimumCost(int n, int m, vector<vector<int>> &connections)
{
    // making the adjacency list
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto it : connections)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    // now we will use prim's algorithm to find the minimum cost
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> vis(n + 1, false);

    int sum = 0;

    pq.push({0, 1});

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

    // if all the nodes are not visited, then return -1
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            return -1;
        }
    }

    return sum;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> connections(m, vector<int>(3));

    for (int i = 0; i < m; i++)
    {
        cin >> connections[i][0] >> connections[i][1] >> connections[i][2];
    }

    cout << getMinimumCost(n, m, connections) << endl;

    return 0;
}