/*
Approach: Backtracking

1. Start from a source and try assigning every color to it.
2. If we can assign a color, check for the next vertex, using recursion.
3. when the source reaches the last vertex, return true.

Time Complexity: O(m^n)
Space Complexity: O(n)
*/
class Solution
{
public:
    bool isSafe(bool graph[101][101], int assignedColor, int n, vector<int> &color, int source)
    {
        for (int i = 0; i < n; i++)
        {
            if (graph[source][i] && color[i] == assignedColor)
                return false;
        }
        return true;
    }

    bool solve(bool graph[101][101], int m, int n, vector<int> &color, int source)
    {
        // base case
        if (source == n)
            return true;

        // recursive case
        for (int i = 0; i < m; i++)
        {
            if (isSafe(graph, i, n, color, source))
            {
                color[source] = i;
                if (solve(graph, m, n, color, source + 1))
                    return true;
                color[source] = -1;
            }
        }
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n)
    {
        // generating color array to assign colors to vertices
        vector<int> color(n, -1);
        int source = 0;

        return solve(graph, m, n, color, source);
    }
};