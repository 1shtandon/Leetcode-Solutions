// Approach - Use a stack, push all numbers , if encounter an operator then apply operation on top two values and push the result. Last obtained value is result
// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int n = tokens.size();
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            if (tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if (tokens[i] == "+")
                    s.push(a + b);
                else if (tokens[i] == "-")
                    s.push(b - a);
                else if (tokens[i] == "*")
                    s.push((long long int)a * (long long int)b);
                else if (tokens[i] == "/")
                    s.push(b / a);
            }
            else
                s.push(stoi(tokens[i]));
        }
        return s.top();
    }
};