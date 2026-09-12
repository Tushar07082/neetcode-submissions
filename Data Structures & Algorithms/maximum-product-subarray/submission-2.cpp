class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int currMax = 1, currMin = 1, ans = nums[0];
        for(int i=0;i<n;i++){
            int newMax = max({nums[i], nums[i]*currMax, nums[i]*currMin});
            int newMin = min({nums[i], nums[i]*currMax, nums[i]*currMin});

            currMax = newMax;
            currMin = newMin;

            ans = max(ans, currMax);
        }
        return ans;
    }
};
