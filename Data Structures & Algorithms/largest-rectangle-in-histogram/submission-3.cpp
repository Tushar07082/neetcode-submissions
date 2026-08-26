class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        for(int i=0;i<n;i++){ 
            while(!st.empty() && heights[i] <= heights[st.top()]){
                int poppedIndex = st.top();
                st.pop();
                int left = st.empty()? -1: st.top();
                int right = i;
                ans = max(ans, heights[poppedIndex]*(right-left-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int poppedIndex = st.top();
            st.pop();
            int left = st.empty()? -1: st.top();
            int right = n;
            ans =  max(ans, heights[poppedIndex]*(right-left-1));
        }
        return ans;
    }
};
