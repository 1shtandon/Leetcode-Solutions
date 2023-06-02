
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1])
            return -1;
        queue<pii> q;
        q.push({0, 0});
        int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        vector<vector<int>> dist(n, vector<int>(n, -1));
        dist[0][0] = 1;
        while (!q.empty())
        {
            pii curr = q.front();
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int x = curr.first + dir[i][0];
                int y = curr.second + dir[i][1];
                if (x >= 0 && x < n && y >= 0 && y < n && !grid[x][y] && dist[x][y] == -1)
                {
                    dist[x][y] = dist[curr.first][curr.second] + 1;
                    q.push({x, y});
                }
            }
        }
        return dist[n - 1][n - 1];
    }
};
