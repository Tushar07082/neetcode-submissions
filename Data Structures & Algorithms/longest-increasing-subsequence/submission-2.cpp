class Solution {
public:
    int solve(vector<int> &nums, int i, int last, vector<vector<int>> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i][last+1001] != -1) return dp[i][last+1001];
        
        int use = 0, skip = 0;
        // cout<<last<<" "<<nums[i]<<endl;
        if(nums[i] > last){
            use = 1+solve(nums , i+1, nums[i], dp);
        }
        skip = solve(nums, i+1, last, dp);
        return dp[i][last+1001] = max(use, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int> (2002, -1));
        return solve(nums, 0, -1001, dp);
    }
};
