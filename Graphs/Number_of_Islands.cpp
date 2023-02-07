/*
Approach : Breadth First Search
1. Observing the question and test cases carefully, we can see that the solution is all about counting the starting points
from where the traversal can be done(say, BFS)
2. Now iterating through every 1 in the grid, if its not visited, we apply bfs on it and increase the ctr.
3. Notice, that in the bfs function, for neighbours first we check vertically in rows, and then horizontally in cols with 2 loops.

Time Complexity : O(n*m)
Space Complexity : O(n*m)
*/

class Solution
{
private:
    void bfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        vis[row][col] = true;
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // now for checking all neighbours in 4 direction we run loop
            for (int delx = -1; delx <= 1; delx++)
            {

                int neighbourRow = x + delx;
                int neighbourCol = y;

                if (neighbourRow < rows and neighbourCol < cols and neighbourRow >= 0 and neighbourCol >= 0 and !vis[neighbourRow][neighbourCol] and grid[neighbourRow][neighbourCol] == '1')
                {
                    vis[neighbourRow][neighbourCol] = true;
                    q.push({neighbourRow, neighbourCol});
                }
            }
            for (int dely = -1; dely <= 1; dely++)
            {

                int neighbourRow = x;
                int neighbourCol = y + dely;

                if (neighbourRow < rows and neighbourCol < cols and neighbourRow >= 0 and neighbourCol >= 0 and !vis[neighbourRow][neighbourCol] and grid[neighbourRow][neighbourCol] == '1')
                {
                    vis[neighbourRow][neighbourCol] = true;
                    q.push({neighbourRow, neighbourCol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        int islands = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!vis[i][j] and grid[i][j] == '1')
                {
                    islands++;
                    bfs(i, j, vis, grid);
                }
            }
        }

        return islands;
    }
};