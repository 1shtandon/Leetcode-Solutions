#include <bits/stdc++.h>

using namespace std;

string smallestNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    string ans = "";
    int n = nums.size();
    int i = 0;
    while (i < n && nums[i] == 0)
        i++;
    if (i == n)
        return "0";
    ans += to_string(nums[i]);
    for (int j = 0; j < i; j++)
        ans += to_string(nums[j]);
    for (int j = i + 1; j < n; j++)
        ans += to_string(nums[j]);
    return ans;
}

string smallestSpecialNumber(string str)
{
    // Map of special words
    unordered_map<int, string> specialWords = {
        {0, "zero"},
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"}};

    // Map of characters in shuffled string
    unordered_map<char, int> charCount;
    for (char c : str)
    {
        charCount[c]++;
    }

    // Result string
    vector<int> res;

    // Iterate through special words
    for (int i = 0; i < 10; i++)
    {
        string specialWord = specialWords[i];
        unordered_map<char, int> specialWordCharCount;
        for (char c : specialWord)
        {
            specialWordCharCount[c]++;
        }

        // Check if special word exists in shuffled string
        bool found = true;
        while (found)
        {
            found = true;
            for (auto it : specialWordCharCount)
            {
                if (charCount[it.first] < it.second)
                {
                    found = false;
                    break;
                }
            }

            if (found)
            {
                for (auto it : specialWordCharCount)
                {
                    charCount[it.first] -= it.second;
                }
                res.push_back(i);
            }
        }
    }
    string ans = smallestNumber(res);
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        cout << smallestSpecialNumber(s) << endl;
    }

    return 0;
}
