class Solution {
public:
    int solve(vector<int> &nums, int i, int last, vector<vector<int>> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i][last] != -1) return dp[i][last];
        
        int use = 0, skip = 0;
        if(last == 0 || nums[i] > nums[last-1]){
            use = 1+solve(nums , i+1, i+1, dp);
        }
        skip = solve(nums, i+1, last, dp);
        return dp[i][last] = max(use, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int> (nums.size()+1, -1));
        return solve(nums, 0, 0, dp);
    }
};
