class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &arr)
    {
        int rows = arr.size(), cols = arr[0].size();
        int res = INT_MAX;
        for (int row = 1; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                // no upperleft exists
                if (col == 0)
                {
                    arr[row][col] += min(arr[row - 1][col], arr[row - 1][col + 1]);
                }
                else if (col == cols - 1)
                {
                    arr[row][col] += min(arr[row - 1][col], arr[row - 1][col - 1]);
                }
                else
                {
                    arr[row][col] += min(arr[row - 1][col], min(arr[row - 1][col + 1], arr[row - 1][col - 1]));
                }
            }
        }
        res = *min_element(arr[rows - 1].begin(), arr[rows - 1].end());
        return res;
    }
};