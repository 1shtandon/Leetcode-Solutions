class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // minimum heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({S, 0});

        vector<int> dist(V, INT_MAX);
        dist[S] = 0;

        while (!pq.empty())
        {
            int curr = pq.top().first;
            int currDist = pq.top().second;
            pq.pop();

            for (auto it : adj[curr])
            {
                int edge = it[0];
                int weight = it[1];

                if (currDist + weight < dist[edge])
                {
                    dist[edge] = currDist + weight;
                    pq.push({edge, dist[edge]});
                }
            }
        }

        return dist;
    }
};

// Time Complexity: O(E logV)
// Auxiliary Space: O(V)  