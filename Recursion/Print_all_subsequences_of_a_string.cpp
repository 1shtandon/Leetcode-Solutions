// gfg question not on practice

/*
Approach : draw the recursion tree for the problem, and code as per the decision making steps
1. for a i/p , print the o/p, when i/p becomes empty
2. now at each step we produce two o/p initialized as the previous o/p , one would take the first char of the stirng and other not
3. similary now call the recursion for both these o.p.
4. TC : O(2^N) , sc : O(N) for the call stack
*/
void helperRecursion(string ip, string op)
{
    // base
    if (input.length() == 0)
    {
        cout << op << endl;
        return;
    }

    // initializing two o/p
    string op1 = op;
    string op2 = op;

    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);

    // recurison on both o/p
    helperRecursion(ip, op1);
    helperRecursion(ip, op2);

    return;
}

void printStrinSubsequences(string s)
{
    string op = "";

    helperRecursion(s, op);
}