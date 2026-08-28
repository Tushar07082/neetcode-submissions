class Solution {
public:
    void findCombinations(vector<int> &nums, int i, int target, vector<vector<int>> &ans, vector<int> &temp){
        if(i==nums.size()){
            if(target == 0) ans.push_back(temp);
            return;
        }
        findCombinations(nums, i+1, target, ans, temp);
        
        if(nums[i] <= target){
            temp.push_back(nums[i]);
            findCombinations(nums, i, target-nums[i], ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       vector<vector<int>> ans;
       vector<int> temp;
       findCombinations(nums, 0, target, ans, temp);
       return ans; 
    }
};
