class Solution {
public:
    vector<unordered_map<int,int>> dp;
    int solve(vector<int> &nums, int i, int target){
        if(i<0 && target != 0) return 0;
        if(i<0 && target==0) return 1;
        if(dp[i].find(target) != dp[i].end()) return dp[i][target];

        return dp[i][target] = solve(nums, i-1, target-nums[i]) + solve(nums, i-1, target+nums[i]) ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(n+1);
        return solve(nums, n-1, target);
    }
};
