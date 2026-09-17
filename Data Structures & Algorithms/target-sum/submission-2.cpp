class Solution {
public:
    vector<unordered_map<int, int>> dp;
    int solve(const vector<int>& nums, int i, int target) {
        if (i < 0) {
            return target == 0;
        }

        auto it = dp[i].find(target);
        if (it != dp[i].end()) {
            return it->second;
        }

        int ways =
            solve(nums, i - 1, target - nums[i]) +
            solve(nums, i - 1, target + nums[i]);

        return dp[i][target] = ways;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(n, {});
        return solve(nums, n-1, target);
    }
};
