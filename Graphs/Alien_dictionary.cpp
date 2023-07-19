class Solution
{
public:
    string findOrder(string dict[], int N, int K)
    {
        /*
        Approach : Compare adjacent words pair wise, and determine the smaller element in the order
        Now, this element would have an edge to the corresponding greater element in the graph.
        So, following these steps, we first make a directed graph with nodes 0 , 1, 2, 3 from the letters.
        Then, just applying topological sort will give us the ordering.
        */

        vector<int> adj[K];
        vector<int> indegree(K, 0);
        string ans = "";

        // making adjacency list
        for (int i = 0; i < N - 1; i++)
        {
            string word1 = dict[i];
            string word2 = dict[i + 1];

            for (int j = 0; j < min(word1.length(), word2.length()); j++)
            {
                if (word1[j] != word2[j])
                {
                    // edge from smaller element to greater element
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    indegree[word2[j] - 'a']++;
                    break;
                }
            }
        }

        queue<int> q;
        for (int i = 0; i < K; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            ans += (curr + 'a');

            for (auto neighbours : adj[curr])
            {
                indegree[neighbours]--;

                if (!indegree[neighbours])
                    q.push(neighbours);
            }
        }

        if (ans.length() != K)
            return "";

        return ans;
    }
};