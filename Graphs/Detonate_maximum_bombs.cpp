 class Solution {
public:
    void dfs(int node, vector<int> &visited, vector<int> adj[], int &cnt){
        visited[node] = 1;
        cnt++;

        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour, visited, adj, cnt);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adj[n];

        for(int i=0; i<n; i++){
            long long int x0, y0, r0;
            x0 = bombs[i][0];
            y0 = bombs[i][1];
            r0 = bombs[i][2];

            for(int j=0; j<n; j++){
                if(i != j){
                    long long int x, y;
                    x = abs(x0 - bombs[j][0]);
                    y = abs(y0 - bombs[j][1]);

                    if(x*x + y*y <= r0*r0){
                        adj[i].push_back(j);
                    }
                }
            }
        }

        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            int cnt = 0;
            vector<int> visited(n, 0);
            dfs(i, visited, adj, cnt);

            ans = max(ans, cnt);
        }

        return ans;
    }
};