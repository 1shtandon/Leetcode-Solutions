class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size(), cols = matrix[0].size();

        if (target > matrix[rows - 1][cols - 1] or target < matrix[0][0])
            return false;

        int low = 0, high = rows * cols - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int row = mid / cols;
            int col = mid % cols;
            int midElement = matrix[row][col];
            if (midElement == target)
                return true;
            else if (midElement > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return false;
    }
};