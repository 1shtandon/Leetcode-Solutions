/*
Approach :
1. If the number of rows is 1, then the string is returned as it is.
2. Else , we create a vector of strings of size numRows.
3. We traverse the string and add the characters to the string at the index of the vector.
4. We keep a pointer which keeps track of the index of the vector.
5. We also keep a direction variable which keeps track of the direction in which the pointer is moving.
6. If the pointer is at the last index or the first index, we change the direction of the pointer.
7. We return the string by concatenating all the strings in the vector.

Time Complexity : O(n)
Space Complexity : O(n)
*/

class Solution
{
public:
    string convert(string s, int numRows)
    {
        int len = s.length();

        if (numRows <= 1)
            return s;

        vector<string> zigzag(numRows, "");

        int ptr = 0, direction = -1;

        for (int i = 0; i < len; i++)
        {

            if (ptr == numRows - 1 or ptr == 0)
                direction *= (-1);

            zigzag[ptr] += s[i];

            if (direction == 1)
                ptr++;

            else
                ptr--;
        }

        string res;

        for (auto &x : zigzag)
            res += x;

        return res;
    }
};