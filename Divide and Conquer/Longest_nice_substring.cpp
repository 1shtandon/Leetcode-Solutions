class Solution
{
public:
    string longestNiceSubstring(string s)
    {
        unordered_set<char> st(s.begin(), s.end());
        int n = s.length();
        // using divide and conquer approach
        // we need to find that char around which there would be largest ans
        // this would be char whose corresponding lower/upper doesn't exist
        // so ans would be from left or right to this character

        for (int i = 0; i < n; i++)
        {
            if (st.find(tolower(s[i])) == st.end() or st.find(toupper(s[i])) == st.end())
            {
                string leftString = longestNiceSubstring(s.substr(0, i));
                string rightString = longestNiceSubstring(s.substr(i + 1));

                // return longest ans
                return leftString.length() >= rightString.length() ? leftString : rightString;
            }
        }

        // if that condition never comes, that means for every character, corresponding char is present.
        return s;
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n)
