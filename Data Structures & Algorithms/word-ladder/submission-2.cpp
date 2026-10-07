class Solution {
public:
    int findShortestPathLength(int start, int end, vector<vector<bool>> &adj){
        int n = adj.size();
        queue<int> q;
        vector<int> dist(n, INT_MAX);
        dist[start] = 1;
        q.push(start);

        while(!q.empty()){
            auto node = q.front();q.pop();

            for(int i=0;i<n;i++){
                if(1 + dist[node] < dist[i] && adj[node][i]== true){
                    dist[i] = 1 + dist[node];
                    q.push(i);
                }
            }
        }
        return dist[end];
    }

    int isDist1(string x, string y){
        int n = x.size(), ans = 0;
        for(int i=0;i<n;i++){
            if(x[i] != y[i]) ans++;
        }
        return ans == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), end = -1;
        vector<vector<bool>> adj(n+1, vector<bool> (n+1, false));
        adj[0][0] = false;
        for(int j=1;j<=n;j++){
            if(wordList[j-1]==endWord) end = j;
            adj[0][j] = isDist1(beginWord, wordList[j-1]);
        }
        if(end == -1) return 0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(i==j) adj[i][j] = false;
                else{
                    adj[i][j] = isDist1(wordList[i-1], wordList[j-1]);
                    adj[j][i] = adj[i][j];
                } 
            }
        }
        int ans = findShortestPathLength(0, end, adj);
        return ans == INT_MAX ? 0 : ans;
    }
};
