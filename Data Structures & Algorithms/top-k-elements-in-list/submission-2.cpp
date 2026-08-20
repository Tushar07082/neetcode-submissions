class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> vp;
        unordered_map<int,int> count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        
        for(auto i: count){
            vp.push_back({i.second,i.first});
        }
        sort(vp.begin(),vp.end(), greater<>());
        vector<int> answer;
        for(int i=0;i<k && i<vp.size();i++){
            answer.push_back(vp[i].second);
        }
        return answer;
    }
};
