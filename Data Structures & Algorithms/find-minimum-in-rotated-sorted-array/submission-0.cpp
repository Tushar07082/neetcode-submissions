class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int left = 0, right = nums.size()-1;
        int ans = INT_MAX;
        while(left <= right){
            int mid = left + (right-left)/2;
            ans = min(ans, nums[mid]);
            if(mid < n-1 && nums[mid] > nums[mid+1]){
                left = mid+1;
            }else{
                if(nums[mid] > nums[n-1]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
        }
        return ans;
    }
};
