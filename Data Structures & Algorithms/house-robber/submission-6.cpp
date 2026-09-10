class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        int oneStepBefore = 0, twoStepBefore = 0;

        for(int i=0;i<n;i++){
            int curr = max(nums[i]+twoStepBefore, oneStepBefore);
            twoStepBefore = oneStepBefore;
            oneStepBefore = curr;
        }
        return oneStepBefore;
    }
};
