class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto edge: times){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // for(int i=0;i<=n;i++){
        //     cout<<i<<"-> ";
        //     for(auto x : adj[i]){
        //         cout<<x.first<<" "<<x.second<<" , ";
        //     }
        //     cout<<endl;
        // }

        vector<int> mp(n+1, INT_MAX);
        mp[k] = 0;
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0, k});

        while(!q.empty()){
            auto [dist, node] = q.top(); q.pop();
            
            // cout<<node<<" "<<dist<<endl;
            for(auto [node1, dist1]: adj[node]){
                if(dist1 + dist < mp[node1]){
                    q.push({dist1 + dist, node1});
                    mp[node1] = dist1+dist;
                }
            }
        }

        int ans = -1;
        for(int i=1;i<=n;i++){
            if(mp[i]==INT_MAX) return -1;
            else ans = max(ans, mp[i]);
        }

        return ans;
    }
};
