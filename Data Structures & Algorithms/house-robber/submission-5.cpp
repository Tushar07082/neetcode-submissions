class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        int oneStepBefore = max(nums[0], nums[1]), twoStepBefore = nums[0];

        for(int i=2;i<n;i++){
            int curr = max(nums[i]+twoStepBefore, oneStepBefore);
            twoStepBefore = oneStepBefore;
            oneStepBefore = curr;
        }
        return oneStepBefore;
    }
};
