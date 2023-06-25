class Solution
{
public:
    vector<string> res;
    string dir = "DLRU";

    void solve(vector<vector<int>> &m, string path, int n, int row, int col, vector<vector<int>> &visited, vector<int> &delRow, vector<int> &delCol)
    {
        // base case
        if (row == n - 1 and col == n - 1)
        {
            res.push_back(path);
            return;
        }

        // try for every possible direction if its valid to move
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if (newRow >= 0 and newRow < n and newCol < n and newCol >= 0 and visited[newRow][newCol] == 0 and m[newRow][newCol] == 1)
            {
                visited[row][col] = 1;
                path.push_back(dir[i]);
                solve(m, path, n, newRow, newCol, visited, delRow, delCol);
                path.pop_back();
                visited[row][col] = 0;
            }
        }

        return;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        if (m[0][0] == 0 or m[n - 1][n - 1] == 0)
            return {"-1"};

        vector<vector<int>> visited(n, vector<int>(n, 0));

        string path = "";

        vector<int> delRow = {1, 0, 0, -1};
        vector<int> delCol = {0, -1, 1, 0};

        solve(m, path, n, 0, 0, visited, delRow, delCol);

        return res;
    }
};

/*
Time Complexity: O(4^(n*n))
Space Complexity: O(n*n)
*/