class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int sz = mat.size();
        int res = 0;
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                if (i == j or i + j == sz - 1)
                    res += mat[i][j];
            }
        }

        return res;
    }
};