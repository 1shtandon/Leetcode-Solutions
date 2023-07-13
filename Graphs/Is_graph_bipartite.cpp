// A bipartite graph, also called a bigraph, is a set of graph vertices decomposed into two disjoint sets such that no two graph vertices within the same set are adjacent.A bipartite graph is a special case of a k - partite graph with k = 2.
// Note : All acyclic graphs are bipartite. A cyclic graph is bipartite iff all its cycles are of even length

/*
Approach : Graph coloring
1. To find if the graph is bipartite, we color the graph with just two colors, say 0 and 1.
2. If every adjacent nodes can be given different color, we can say that the graph is bipartite.
3. If we find that the adjacent node to any given node is already colored with the same color than, return false.
4. Performing breadth first search for the traversal.
*/

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        // number of nodes
        int n = graph.size();
        // inititally no node is colored so -1
        vector<int> color(n, -1);
        // starting from 1st node and coloring it 0
        color[0] = 0;

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (i == 0 or color[i] == -1)
            {
                q.push(i);

                // applying bfs now
                while (!q.empty())
                {
                    int curr = q.front();
                    q.pop();

                    for (auto &neighbour : graph[curr])
                    {
                        // if not colored, then color with alternate color
                        if (color[neighbour] == -1)
                        {
                            color[neighbour] = 1 - color[curr];
                            q.push(neighbour);
                        }

                        // if neighbour has same color then return false
                        else if (color[neighbour] == color[curr])
                        {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

// depth first search approach

class Solution
{
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &color, int curr, int col)
    {

        // color the current node
        color[curr] = col;

        // for all the neighbours
        for (auto &neighbour : graph[curr])
        {
            // if neighbour is not colored
            if (color[neighbour] == -1)
            {
                // if neighbour can't be colored with alternate color then return false
                if (!dfs(graph, color, neighbour, 1 - col))
                    return false;
            }

            // if neighbour has same color then return false
            else if (color[neighbour] == color[curr])
            {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        // number of nodes
        int n = graph.size();
        // inititally no node is colored so -1
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                // if any component is not bipartite then return false
                if (!dfs(graph, color, i, 0))
                    return false;
            }
        }

        return true;
    }
};