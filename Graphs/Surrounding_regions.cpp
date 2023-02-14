/*
Approach: Depth First Search
1. Convert all the Os which cant be captured to -.
2. Convert all the - to Os.
3. Convert all the Os to Xs.

Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/

class Solution
{
private:
    void dfs(int row, int col, vector<vector<char>> &board)
    {
        int rows = board.size(), cols = board[0].size();
        if (row < 0 or row >= rows or col < 0 or col >= cols or board[row][col] != 'O')
            return;

        board[row][col] = '-';

        // now travelling in 4 directions
        dfs(row - 1, col, board);
        dfs(row + 1, col, board);
        dfs(row, col - 1, board);
        dfs(row, col + 1, board);
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int rows = board.size(), cols = board[0].size();
        if (rows < 3 or cols < 3)
            return;
        // all the 0s which cant be captured must be turned to "-"
        // for doing so, we can use dfs traversal

        for (int i = 0; i < rows; i++)
        {
            // checking for first col of every row
            if (board[i][0] == 'O')
                dfs(i, 0, board);

            // checking for last col of every row
            if (board[i][cols - 1] == 'O')
                dfs(i, cols - 1, board);
        }

        for (int j = 0; j < cols; j++)
        {
            // checking for first row of every col
            if (board[0][j] == 'O')
                dfs(0, j, board);

            // checking for last row of every col
            if (board[rows - 1][j] == 'O')
                dfs(rows - 1, j, board);
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '-')
                    board[i][j] = 'O';
            }
        }
    }
};