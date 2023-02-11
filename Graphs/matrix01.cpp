/*
Approach : Breadth First Search
1. We will first find all the 0's and push them into the queue
2. Then apply bfs on the queue and find the distance of all the 1's from the 0's
3. We will use a visited array to keep track of the nodes which are already visited

Time Complexity : O(n*m)
Space Complexity : O(n*m)
*/

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        vector<vector<int>> res(rows, vector<int>(cols, 0));

        // queue would store coordinates in pair along with steps
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat[i][j] == 0)
                {
                    vis[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }
        vector<int> delrow = {-1, 1, 0, 0};
        vector<int> delcol = {0, 0, 1, -1};

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            res[row][col] = steps;

            for (int i = 0; i < 4; i++)
            {
                int neighbourRow = row + delrow[i];
                int neighbourCol = col + delcol[i];

                if (neighbourRow >= 0 and neighbourRow < rows and neighbourCol >= 0 and neighbourCol < cols and !vis[neighbourRow][neighbourCol] and mat[neighbourRow][neighbourCol] == 1)
                {
                    vis[neighbourRow][neighbourCol] = true;
                    q.push({{neighbourRow, neighbourCol}, steps + 1});
                }
            }
        }

        return res;
    }
};