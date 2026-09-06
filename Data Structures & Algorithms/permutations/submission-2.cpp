class Solution {
public:
    void findPermutations(vector<int> &nums, int i, vector<vector<int>> &ans){
        if(i >= nums.size()){
            ans.push_back(nums);
            return;
        }
        findPermutations(nums, i+1, ans);
        for(int j=i+1;j<nums.size();j++){
            swap(nums[i], nums[j]);
            findPermutations(nums, i+1, ans);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        findPermutations(nums, 0, ans);
        return ans;
    }
};
