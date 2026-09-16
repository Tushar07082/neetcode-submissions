class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n = pre.size();
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        int maxFreq = 0;
        for(int i=0;i<n;i++){
            if(pre[i][0] == pre[i][1]) return false;
            indegree[pre[i][0]]++;
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            if(numCourses == 0) return true;
            int x = q.front();q.pop();
            numCourses--;

            for(int i=0;i<adj[x].size();i++){
                indegree[adj[x][i]]--;
                if(indegree[adj[x][i]]==0) q.push(adj[x][i]);
            }
        }
        return numCourses==0;
    }
};
