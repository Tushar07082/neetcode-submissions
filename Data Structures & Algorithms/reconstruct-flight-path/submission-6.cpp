class Solution {
public:
    void dfs(unordered_map<string, multiset<string>> &mp, string node, vector<string> &curr){
        
        while (!mp[node].empty()) {
            string next = *mp[node].begin();

            mp[node].erase(mp[node].begin());

            dfs(mp, next, curr);
        }

        curr.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> mp;
        for(auto ticket: tickets){
            mp[ticket[0]].insert(ticket[1]);
        }
        vector<string> ans;
        dfs(mp, "JFK", ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
