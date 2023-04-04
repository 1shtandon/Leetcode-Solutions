class Solution
{
public:
    int partitionString(string s)
    {
        int substrings = 1;
        set<char> st;
        for (auto c : s)
        {
            if (st.count(c) == 1)
            {
                st.clear();
                substrings++;
            }

            st.insert(c);
        }
        return substrings;
    }
};