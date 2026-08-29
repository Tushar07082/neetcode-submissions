class Solution {
public:
    void findSubsets(vector<int> &nums, int i, vector<int> &subset, vector<vector<int>> &st){
        if(i>=nums.size()){
            st.push_back(subset);
            return;
        }
        // when you are taking nums[i] you can consider its duplicates
        subset.push_back(nums[i]);
        findSubsets(nums, i + 1, subset, st);
        subset.pop_back();

        //when you are not taking nums[i] skip all its duplicates
        while(i + 1 < nums.size() &&
              nums[i] == nums[i + 1]) {
            i++;
        }

        findSubsets(nums, i + 1, subset, st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> st;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        findSubsets(nums, 0, subset, st);
        return {st.begin(), st.end()};
    }
};
