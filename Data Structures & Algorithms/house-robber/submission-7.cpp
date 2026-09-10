class Solution {
public:
    int rob(vector<int>& nums) {
        int oneStepBefore = 0, twoStepBefore = 0;

        for(auto i: nums){
            int curr = max(i+twoStepBefore, oneStepBefore);
            twoStepBefore = oneStepBefore;
            oneStepBefore = curr;
        }
        return oneStepBefore;
    }
};
