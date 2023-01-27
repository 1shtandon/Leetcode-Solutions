/*
Approach: Dynamic Programming
1. Create a set of all words
2. For each word, initialize a dp array of size word.length() + 1
3. if dp[i] == 1, it means that the substring from 0 to i is a concatenation of words in the set
4. For each word, check if the substring from i to j is present in the set. If yes, then dp[j] = 1
5. If dp[word.length()] == 1, then the word is a concatenation of words in the set
6. Return the list of all such words

Time Complexity: O(n * m^2) where n is the number of words and m is the length of the longest word
Space Complexity: O(n * m) where n is the number of words and m is the length of the longest word
*/

class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        unordered_set<string> words_set;
        for (auto &x : words)
        {
            words_set.insert(x);
        }
        vector<string> res;

        for (auto &word : words)
        {
            int len = word.length();
            vector<int> dp(len + 1, 0);

            dp[0] = 1;
            for (int i = 0; i < len; i++)
            {
                if (dp[i] == 0)
                    continue;

                for (int j = i + 1; j <= len; j++)
                {
                    if (j - i < len and words_set.count(word.substr(i, j - i)))
                        dp[j] = 1;
                }
            }
            if (dp[len] == 1)
                res.push_back(word);
        }

        return res;
    }
}