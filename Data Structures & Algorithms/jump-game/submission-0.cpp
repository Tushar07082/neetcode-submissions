class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumpLeft = 1, n = nums.size();
        for(int i=0;i<n-1;i++){
            jumpLeft--;
            if(jumpLeft == 0 && nums[i]==0){
                return false;
            }else{
                jumpLeft = max(nums[i], jumpLeft);
            }
        }
        return true;
    }
};
