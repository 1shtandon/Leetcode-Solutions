class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int n = letters.size();

        if (letters[0] > target)
            return letters[0];

        else if (target >= letters[letters.size() - 1])
            return letters[0];

        char res;
        int left = 0, right = n - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (letters[mid] > target)
            {
                res = letters[mid];
                right = mid - 1;
            }

            else
            {
                left = mid + 1;
            }
        }
        return res;
    }
};