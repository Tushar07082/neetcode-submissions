class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0, n = nums.size();
        vector<int> ans;
        multiset<int, greater<int>> mst;
        for(int j = 0;j<n;j++){
            mst.insert(nums[j]);
            if(j-i == k){
                mst.erase(mst.find(nums[i]));
                i++;
            }
            if(j>=k-1){
                ans.push_back(*mst.begin());
            } 
        }
        return ans;
    }
};
