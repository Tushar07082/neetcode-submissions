class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        int i=0, j=n-1, leftMax = 0, rightMax = -1;
        while(i<=j){
            if(height[i]<leftMax){
                ans += leftMax - height[i];
            }else{
                leftMax = height[i];
            }
            if(height[j]<rightMax){
                ans += rightMax - height[j];
            }else{
                rightMax = height[j];
            }
            if(height[i]>height[j]){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};
