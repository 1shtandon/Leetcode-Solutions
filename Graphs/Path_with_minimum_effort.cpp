class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        // using dijkstra's algo
        int n = heights.size();
        int m = heights[0].size();

        // minimum heap to store {effort, {x, y}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // distance array
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // pushing source
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        // directions
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // applying dijkstra's algo
        while (!pq.empty())
        {
            int currEffort = pq.top().first;
            int currX = pq.top().second.first;
            int currY = pq.top().second.second;
            pq.pop();

            // if we reach destination
            if (currX == n - 1 and currY == m - 1)
                return currEffort;

            // if we have already visited this node with less effort
            if (currEffort > dist[currX][currY])
                continue;

            // traversing in all 4 directions
            for (int i = 0; i < 4; i++)
            {
                int x = currX + dir[i][0];
                int y = currY + dir[i][1];

                // if valid
                if (x >= 0 and x < n and y >= 0 and y < m)
                {
                    // if we can reach this node with less effort
                    if (max(currEffort, abs(heights[x][y] - heights[currX][currY])) < dist[x][y])
                    {
                        dist[x][y] = max(currEffort, abs(heights[x][y] - heights[currX][currY]));
                        pq.push({dist[x][y], {x, y}});
                    }
                }
            }
        }

        return -1;
    }
};