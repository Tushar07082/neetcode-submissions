class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        int oneStepBefore = 0, twoStepBefore = 0;

        for(int i=1;i<n;i++){
            int curr = max(nums[i]+twoStepBefore , oneStepBefore);
            twoStepBefore = oneStepBefore;
            oneStepBefore = curr;
        }

        int firstElementNotSelected = oneStepBefore;

        oneStepBefore = 0; twoStepBefore = 0;

        for(int i=0;i<n-1;i++){
            int curr = max(nums[i]+twoStepBefore , oneStepBefore);
            twoStepBefore = oneStepBefore;
            oneStepBefore = curr;
        }
        
        return max(firstElementNotSelected, oneStepBefore);
    }
};
