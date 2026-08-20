class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()) return "";
        auto &values = mp[key];
        int left = 0, right = values.size(), floor = -1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(values[mid].first > timestamp){
                right = mid;
            }else{
                floor = mid;
                left = mid+1;
            }
        }
        if(floor == -1) return "";
        return values[floor].second;
    }
};

