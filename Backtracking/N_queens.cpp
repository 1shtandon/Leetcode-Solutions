/*
Approach 1: Backtracking

1. We will use backtracking to solve this problem.
2. use a vector of strings to store the current combination of strings.
3.For each column, we will check if we can place a queen in any of the rows of that column.
4. If we can place a queen, we will place it and move to the next column by recursion and backtrack.
5. here for checking if valid we are running 3 times O(n).
*/

class Solution
{
public:
    vector<vector<string>> res;

    bool isValid(int row, int col, vector<string> &chessBoard, int &n)
    {
        int tempRow = row;
        int tempCol = col;

        // we have to check in total 3 directions, left, upperleft , and lowerleft for attack by previous put queens

        // left direction check
        while (col >= 0)
        {
            if (chessBoard[row][col] == 'Q')
            {
                // attack found
                return false;
            }

            col--;
        }

        // upper left check
        col = tempCol;
        while (row >= 0 and col >= 0)
        {
            if (chessBoard[row][col] == 'Q')
            {
                // attack found
                return false;
            }

            row--;
            col--;
        }

        // lower left check
        col = tempCol, row = tempRow;
        while (col >= 0 and row < n)
        {
            if (chessBoard[row][col] == 'Q')
            {
                // attack found
                return false;
            }

            row++;
            col--;
        }

        // finally if all check pass, then return true
        return true;
    }

    void solve(vector<string> chessBoard, int &n, int col)
    {
        if (col == n)
        {
            res.push_back(chessBoard);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isValid(row, col, chessBoard, n))
            {
                // if its valid then put a queen, apply recursion on next col and backtrack
                chessBoard[row][col] = 'Q';

                solve(chessBoard, n, col + 1);

                chessBoard[row][col] = '.';
            }
        }

        return;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        string s(n, '.');

        vector<string> chessBoard(n, s);

        solve(chessBoard, n, 0);

        return res;
    }
};

/*
Appraoch 2: Backtracking

1. Here we will use 3 vectors to store the information of the rows, cols and diagonals using the formula:
row = i
col = j

left diagonal = i + j
right diagonal = i - j + n - 1

*/

class Solution
{
public:
    vector<vector<string>> res;

    void solve(vector<string> &chessBoard, int &n, int col, vector<int> &rows, vector<int> &leftDiagonal, vector<int> &rightDiagonal)
    {
        if (col == n)
        {
            res.push_back(chessBoard);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (rows[row] == 0 and leftDiagonal[row + col] == 0 and rightDiagonal[row - col + n - 1] == 0)
            {
                // if its valid then put a queen, apply recursion on next col and backtrack
                chessBoard[row][col] = 'Q';

                rows[row] = 1;
                leftDiagonal[row + col] = 1;
                rightDiagonal[row - col + n - 1] = 1;

                solve(chessBoard, n, col + 1, rows, leftDiagonal, rightDiagonal);

                chessBoard[row][col] = '.';

                rows[row] = 0;
                leftDiagonal[row + col] = 0;
                rightDiagonal[row - col + n - 1] = 0;
            }
        }

        return;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        string s(n, '.');

        vector<string> chessBoard(n, s);

        vector<int> rows(n, 0);
        vector<int> leftDiagonal(2 * n - 1, 0);
        vector<int> rightDiagonal(2 * n - 1, 0);

        solve(chessBoard, n, 0, rows, leftDiagonal, rightDiagonal);

        return res;
    }
};