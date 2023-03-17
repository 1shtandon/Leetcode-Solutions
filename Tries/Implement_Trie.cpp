/*
Approach : Using Hashmap

1. We will use two hashmaps, one for storing the words and other for storing the prefixes.
2. For inserting a word, we will insert the word in the wordMap and also insert all the prefixes of the word in the prefixMap.
3. For searching a word, we will check if the word is present in the wordMap.
4. For searching a prefix, we will check if the prefix is present in the prefixMap.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Trie
{
public:
    unordered_map<string, int> wordMap, prefixMap;
    Trie()
    {
    }

    void insert(string word)
    {
        wordMap[word] = 1;
        for (int i = 0; i < word.length(); i++)
        {
            prefixMap[word.substr(0, i + 1)] = 1;
        }
    }

    bool search(string word)
    {
        if (wordMap.find(word) != wordMap.end())
            return true;
        return false;
    }

    bool startsWith(string prefix)
    {
        if (prefixMap.find(prefix) != prefixMap.end())
            return true;
        return false;
    }
};