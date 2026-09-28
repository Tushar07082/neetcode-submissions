class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto edge: times){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        for(int i=0;i<=n;i++){
            cout<<i<<"-> ";
            for(auto x : adj[i]){
                cout<<x.first<<" "<<x.second<<" , ";
            }
            cout<<endl;
        }

        unordered_map<int,int> mp;
        mp.insert({k, 0});
        queue<pair<int,int>> q;
        q.push({k, 0});

        while(!q.empty()){
            auto [node, dist] = q.front(); q.pop();
            
            cout<<node<<" "<<dist<<endl;
            for(auto [node1, dist1]: adj[node]){
                auto it = mp.find(node1);
                if(it == mp.end() || dist1 + dist < it->second){
                    q.push({node1, dist1 + dist});
                    mp[node1] = dist1+dist;
                }
            }
        }

        int ans = -1;
        for(int i=1;i<=n;i++){
            auto it = mp.find(i);
            if(it==mp.end()) return -1;
            else ans = max(ans, it->second);
        }

        return ans;
    }
};
