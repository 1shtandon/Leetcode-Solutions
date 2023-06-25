/*
Approach: Backtracking

1. We will check for every empty cell if we can place a number or not.
2. If we can place a number, chcck for every number from 1 to 9, if it is valid to place.
3. If it is valid to place, place it and call the function recursively for the next empty cell.
4. This recursive call will return true if we can solve the sudoku, else we will backtrack and try for the next number.
5. If we are not able to place any number, return false.

Time Complexity: O(9^(n*n))
Space Complexity: O(n*n)
*/
class Solution
{
public:
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        int i, j;
        for (i = 0; i < 9; i++)
        {
            // row check
            if (board[i][col] == c)
                return false;
            // col check
            if (board[row][i] == c)
                return false;
            // box check
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        int i, j;
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(board, i, j, c))
                        {
                            board[i][j] = c;
                            if (solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};