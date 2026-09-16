class Solution {
public:
    bool dfs(const vector<vector<int>> &adj, int i, vector<bool> &visited, int last){
        if(visited[i]==true) return false;

        visited[i] = true;

        for(auto node: adj[i]){
            if(node != last && dfs(adj, node, visited, i) == false) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        bool ans = dfs(adj, 0, visited, -1);
        if(ans == false) return false;
        for(int i=0;i<n;i++){
            if(visited[i]==false) return false;
        }
        
        return true;

    }
};
