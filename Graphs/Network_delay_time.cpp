class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // since time isnt negative so dijstra would work here

        vector<pair<int, int>> adj[n + 1];

        for (auto time : times)
        {
            adj[time[0]].push_back({time[1], time[2]});
        }

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty())
        {
            int curr = pq.top().second;
            int currDist = pq.top().first;

            pq.pop();

            for (auto it : adj[curr])
            {
                int node = it.first;
                int wt = it.second;

                if (currDist + wt < dist[node])
                {
                    dist[node] = currDist + wt;
                    pq.push({dist[node], node});
                }
            }
        }

        //  + 1 because of 1 indexed elements
        int res = *max_element(dist.begin() + 1, dist.end());

        return res == 1e9 ? -1 : res;
    }
};