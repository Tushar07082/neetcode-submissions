class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        // most intuitive
        vector<int> prefProd(n), suffProd(n);
        prefProd[0] = 1;
        suffProd[n-1] = 1;
        int ans = INT_MIN;
        for(int i=1;i<n;i++){
            prefProd[i] = nums[i-1]!=0 ? prefProd[i-1] * nums[i-1]:1;
            suffProd[n-1-i] = nums[n-i]!=0 ? suffProd[n-i] * nums[n-i]:1;
        }
        for(int i=0;i<n;i++){
            ans = max(ans, max(prefProd[i]*nums[i], max(suffProd[i]*nums[i], nums[i])));
        }
        return ans;
    }
};
