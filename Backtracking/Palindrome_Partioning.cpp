/*
Approach - Backtracking
1. We traverse the string from start to end using dfs.
2. We check if the substring from start to end is a palindrome or not.
3. If it is a palindrome, we add it to the potential candidate.
4. We then call the dfs function again with the next index as start.
5. We backtrack by removing the last element from the potential candidate.

Time Complexity - O(2^n)
Space Complexity - O(n)
*/

class Solution
{
public:
    bool checkPalindrome(string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void dfsTraversal(string &s, int start, vector<vector<string>> &res, vector<string> &potentialCandidate)
    {
        if(start >= s.length())
        {
            res.push_back(potentialCandidate);
        }

        for(int end = start; end < s.length(); end++)
        {
            if(checkPalindrome(s , start , end))
            {
                potentialCandidate.push_back(s.substr(start , end - start + 1));
                dfsTraversal(s , end + 1 , res , potentialCandidate);
                potentialCandidate.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> potentialCandidate;
        dfsTraversal(s , 0 , res , potentialCandidate);
        return res;
    }
};