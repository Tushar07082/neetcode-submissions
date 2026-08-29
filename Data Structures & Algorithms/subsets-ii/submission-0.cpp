class Solution {
public:
    void findSubsets(vector<int> &nums, int i, vector<int> &subset, set<vector<int>> &st){
        if(i>=nums.size()){
            st.insert(subset);
            return;
        }
        findSubsets(nums, i+1, subset, st);
        subset.push_back(nums[i]);
        findSubsets(nums, i+1, subset, st);
        subset.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        findSubsets(nums, 0, subset, st);
        return {st.begin(), st.end()};
    }
};
