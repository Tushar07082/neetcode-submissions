class Solution {
public:
    bool solve(vector<int> &nums, int i, int sum, unordered_map<int, unordered_map<int,bool>> &mp){
        if(i==nums.size() && sum != 0) {
            return false;
        }
        if(sum == 0) return mp[i][sum] = true;
        if(mp.find(i) != mp.end() && mp[i].find(sum) != mp[i].end()) return mp[i][sum];

        bool use = false;
        if(nums[i]<=sum){
            use = solve(nums, i+1, sum-nums[i], mp);
        }
        bool skip = solve(nums, i+1, sum, mp);
        return mp[i][sum] = use || skip;
    }
    bool canPartition(vector<int>& nums) {
        unordered_map<int, unordered_map<int,bool>> mp;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum%2) return false;
        return solve(nums, 0, totalSum/2, mp);
    }
};
