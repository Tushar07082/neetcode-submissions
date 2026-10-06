class Solution {
    vector<int> parent;
public:
    void make_union(int x, int y){
        if(parent[x] != -1) {
            while(y != -1){
                int z = parent[y];
                parent[y] = parent[x];
                y = z;
            }
        }
        else if(parent[y] != -1) {
            while(x != -1){
                int z = parent[x];
                parent[x] = parent[y];
                x = z;
            }
        }
        else parent[y] = x;
    }
    int findParent(int x){
        if (parent[x] == -1)
            return x;

        return parent[x] = findParent(parent[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.assign(n+1, -1);
        vector<int> ans;
        for(auto edge : edges){
            if(findParent(edge[0]) == findParent(edge[1])) ans = {edge[0], edge[1]};
            else make_union(edge[0], edge[1]);
        }
        return ans;
    }
};
