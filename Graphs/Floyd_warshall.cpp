class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // performing inplace floyd warshall
        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    // check if there is an edge between i and via, and between via and j
                    if (matrix[i][via] != -1 and matrix[via][j] != -1)
                    {
                        // update the shortest distance if necessary
                        if (matrix[i][j] == -1 or matrix[i][j] > (matrix[i][via] + matrix[via][j]))
                            matrix[i][j] = matrix[i][via] + matrix[via][j];
                    }
                }
            }
        }
    }
};
