class Solution {
public:
    void dfs(vector<vector<int>> &adj, int i, vector<bool> &visited){
        if(visited[i]) return;
        visited[i] = true;
        for(auto node: adj[i]){
            dfs(adj, node, visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, 0);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs(adj, i, visited);
                ans++;
            }
        }
        return ans;
    }
};
