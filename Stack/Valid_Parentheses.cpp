/*
Approach : Stack
1. Iterate over the string and push the opening brackets in the stack.
2. If the current character is a closing bracket, then check if the top of the stack is the corresponding opening bracket.
3. If yes, then pop the top element from the stack.
4. If no, then return false.
5. If the stack is empty at the end, then return true.

Time Complexity - O(n)
Space Complexity - O(n)
*/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto &x : s)
        {
            if (x == '(' or x == '{' or x == '[')
                st.push(x);
            else if (x == ')' or x == '}' or x == ']')
            {
                if (st.empty())
                    return false;
                else if (x == ')' and st.top() == '(')
                    st.pop();
                else if (x == '}' and st.top() == '{')
                    st.pop();
                else if (x == ']' and st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};