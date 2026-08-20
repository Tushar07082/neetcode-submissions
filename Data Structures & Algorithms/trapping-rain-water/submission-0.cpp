class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        if(n==1) return ans;
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0] = -1;
        leftMax[1] = 0;
        rightMax[n-1] = -1;
        rightMax[n-2] = n-1;

        for(int i=2;i<n;i++){
            if(height[i-1] > height[leftMax[i-1]]){
                leftMax[i] = i-1; 
            }else{
                leftMax[i] = leftMax[i-1];
            }

            if(height[n-i] > height[rightMax[n-i]]){
                rightMax[n-1-i] = n-i;
            }else{
                rightMax[n-1-i] = rightMax[n-i];
            }
        }

        for(int i=1;i<n-1;i++){
            if(height[i] < height[leftMax[i]] && height[i] < height[rightMax[i]]){
                ans += min(height[leftMax[i]], height[rightMax[i]]) - height[i];
            }
        }
        return ans;
    }
};
