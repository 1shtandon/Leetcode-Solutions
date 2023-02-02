/*
Approach: Hashing
1. We store the order of the letters in a map.
2. Compare each adjacent pair of words.
3. If the letters is different then only we check the order.
4. If the order is not correct, then return false.
5. If the next word is shorter than the current word, then return false.

Time Complexity: O(n*m), where n is the number of words and m is the length of the longest word.
Space Complexity: O(1), since the map will have atmost 26 characters.
*/

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        // ranking the letters as per the order
        unordered_map<char, int> rank;
        int sz = words.size();
        for (int i = 0; i < order.length(); i++)
        {
            rank[order[i]] = i;
        }

        // checking each adjacent pair of words
        for (int i = 0; i < sz - 1; i++)
        {
            string currWord = words[i], nextWord = words[i + 1];
            int len1 = currWord.length(), len2 = nextWord.length();
            for (int j = 0; j < len1; j++)
            {
                // if nextword is shorter than return false
                if (j >= len2)
                    return false;

                if (currWord[j] != nextWord[j])
                {
                    if (rank[currWord[j]] > rank[nextWord[j]])
                        return false;

                    else
                        break;
                }
            }
        }
        return true;
    }
};