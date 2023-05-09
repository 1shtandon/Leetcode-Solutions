class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        // inserting elements in spiral pattern
        while (top <= bottom and left <= right)
        {
            // 1. left to right
            for (int i = left; i <= right; i++)
            {
                res.push_back(matrix[top][i]);
            }
            top++;
            // 2. top to down at right col
            for (int i = top; i <= bottom; i++)
            {
                res.push_back(matrix[i][right]);
            }
            right--;
            // checking for violation
            if (left > right or top > bottom)
                break;
            // 3. Right to left in bottom row
            for (int i = right; i >= left; i--)
            {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
            // 4. bottom to  up in left col
            for (int i = bottom; i >= top; i--)
            {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};