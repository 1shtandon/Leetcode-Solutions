class Solution
{
private:
    void bfs(int row, int col, int color, vector<vector<bool>> &vis, vector<vector<int>> &image)
    {
        int rows = image.size(), cols = image[0].size();
        vis[row][col] = true;
        int target = image[row][col];
        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int delx = -1; delx <= 1; delx++)
            {

                int neighbourRow = x + delx;
                int neighbourCol = y;

                if (neighbourRow < rows and neighbourCol < cols and neighbourRow >= 0 and neighbourCol >= 0 and !vis[neighbourRow][neighbourCol] and image[neighbourRow][neighbourCol] == target)
                {
                    vis[neighbourRow][neighbourCol] = true;
                    image[neighbourRow][neighbourCol] = color;
                    q.push({neighbourRow, neighbourCol});
                }
            }
            for (int dely = -1; dely <= 1; dely++)
            {

                int neighbourRow = x;
                int neighbourCol = y + dely;

                if (neighbourRow < rows and neighbourCol < cols and neighbourRow >= 0 and neighbourCol >= 0 and !vis[neighbourRow][neighbourCol] and image[neighbourRow][neighbourCol] == target)
                {
                    vis[neighbourRow][neighbourCol] = true;
                    image[neighbourRow][neighbourCol] = color;
                    q.push({neighbourRow, neighbourCol});
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int rows = image.size(), cols = image[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        bfs(sr, sc, color, vis, image);
        image[sr][sc] = color;
        return image;
    }
};