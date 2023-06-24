class Solution
{
public:
    /*
        To understand this question, draw the recursion tree for some n
        We have two choices:
        1. Either we put a '('
        2. Or we put a ')'

        But we have some constraints:
        1. We can't put a ')' if we don't have any '('

        so we have to keep track of the number of openBrackets and closeBrackets
        If openBrackets == 0 and closeBrackets == 0, we have found a valid string

        we can only put a closing bracket if :
        openBrackets < closeBrackets
    */

    vector<string> res;

    void solve(int openBrackets, int closeBrackets, string op)
    {
        if (openBrackets == 0 && closeBrackets == 0)
        {
            res.push_back(op);
            return;
        }

        if (openBrackets > 0)
        {
            string op1 = op;
            op1.push_back('(');
            solve(openBrackets - 1, closeBrackets, op1);
        }

        if (closeBrackets > openBrackets)
        {
            string op2 = op;
            op2.push_back(')');
            solve(openBrackets, closeBrackets - 1, op2);
        }

        return;
    }

    vector<string> generateParenthesis(int n)
    {
        string op = "";
        solve(n, n, op);
        return res;
    }
};
