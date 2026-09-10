class Solution {
public:
    int ifIrob(vector<int> &nums, int x, vector<int> &dp){
        if(x==-1) return 0;
        if(dp[x] != -1) return dp[x];
        return dp[x] = max(nums[x]+ ifIrob(nums, x-2, dp), ifIrob(nums, x-1, dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        vector<int> dp(n, -1);
        dp[0] = nums[0];
        return max(ifIrob(nums, n-1, dp), ifIrob(nums, n-2, dp));
    }
};
