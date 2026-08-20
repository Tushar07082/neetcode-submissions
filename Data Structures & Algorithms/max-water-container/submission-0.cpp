class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        vector<int> prefArea(n,0);
        vector<int> suffArea(n,0);
        for(int i=1;i<n;i++){
            prefArea[i] = height[i]*i;
            suffArea[n-1-i] = height[n-1-i]*i;
        }

        int i = 0, j = n-1, ans = 0;
        while(i<j){
            ans = max(min(height[i],height[j])*(j-i),ans);
            int potentialRightArea = suffArea[i]-(i*(n-1-j));
            int potentialLeftArea = prefArea[j]-(j*i);
            if(max(prefArea[i],potentialRightArea) > max(potentialLeftArea,suffArea[j])){
                j--;
            }else{
                i++;
            }
        }

        return ans;
    }
};
