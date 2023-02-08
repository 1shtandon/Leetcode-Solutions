/*
Approach : Breadth  First Search
1. We will first find all the rotten oranges and push them into the queue
2. Then apply bfs on the queue and simultaneously count the number of fresh oranges
3. If the number of fresh oranges is not equal to the number of rotten oranges, then return -1
4. Else return the time

Time Complexity : O(n*m)
Space Complexity : O(n*m)
*/

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        int time = 0, freshOranges = 0;

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        // q would store a pair of pair and int to have row , col and timestamp
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }

                if (grid[i][j] == 1)
                    freshOranges++;
            }
        }

        // now applying bfs because we can simultaneouly rot the oranges from different points, so bfs is right approach

        // for traversing in all 4 directions, the changes in row and col are declared
        int delrow[] = {-1, 0, 0, 1};
        int delcol[] = {0, +1, -1, 0};
        int rottenOranges = 0;
        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second; // tinestamp
            q.pop();
            time = max(time, t);
            for (int i = 0; i < 4; i++)
            {
                int neighbourRow = row + delrow[i];
                int neighbourCol = col + delcol[i];

                if (neighbourRow >= 0 and neighbourRow < rows and neighbourCol >= 0 and neighbourCol < cols and !vis[neighbourRow][neighbourCol] and grid[neighbourRow][neighbourCol] == 1)
                {
                    vis[neighbourRow][neighbourCol] = true;
                    q.push({{neighbourRow, neighbourCol}, t + 1});
                    rottenOranges++;
                }
            }
        }

        if (freshOranges != rottenOranges)
            return -1;

        return time;
    }
};