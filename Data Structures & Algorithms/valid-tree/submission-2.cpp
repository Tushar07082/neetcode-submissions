class Solution {
public:
    void dfs(const vector<vector<int>> &adj, int node, vector<bool> &visited){
        if (visited[node]) {
            return;
        }

        visited[node] = true;

        for (int nextNode : adj[node]) {
            dfs(adj, nextNode, visited);
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(adj, 0, visited);

        for (bool isVisited : visited) {
            if (!isVisited) {
                return false;
            }
        }
        return true;
    }
};
