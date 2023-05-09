class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n));
        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        int ptr = 1;
        while (top <= bottom and left <= right)
        {
            // 1. left to right
            for (int i = left; i <= right; i++)
            {
                matrix[top][i] = ptr;
                ptr++;
            }
            top++;
            // 2. top to down at right col
            for (int i = top; i <= bottom; i++)
            {
                matrix[i][right] = ptr;
                ptr++;
            }
            right--;
            // checking for violation
            if (left > right or top > bottom)
                break;
            // 3. Right to left in bottom row
            for (int i = right; i >= left; i--)
            {
                matrix[bottom][i] = ptr;
                ptr++;
            }
            bottom--;
            // 4. bottom to  up in left col
            for (int i = bottom; i >= top; i--)
            {
                matrix[i][left] = ptr;
                ptr++;
            }
            left++;
        }

        return matrix;
    }
};
