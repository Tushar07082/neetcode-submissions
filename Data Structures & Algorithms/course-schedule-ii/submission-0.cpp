class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        for(auto x: pre){
            if(x[0]==x[1]) return {};

            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }

        queue<int> q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int course = q.front();q.pop();
            // cout<<course<<endl;
            ans.push_back(course);

            for(auto x: adj[course]){
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
        if(ans.size() != n) return {};

        return ans;
    }
};
