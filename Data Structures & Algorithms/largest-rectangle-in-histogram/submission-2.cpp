class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> nse(n, n);
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                // cout<<"popping "<<st.top()<<endl;
                ans = max(ans, heights[st.top()]*(nse[st.top()]-i-1));
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            }
            st.push(i);
            // cout<<i<<" "<<st.top()<<" "<<nse[st.top()]<<" "<<ans<<endl;
        }
        while(!st.empty()){
            ans =  max(ans, heights[st.top()]*(nse[st.top()]));
            st.pop();
        }
        return ans;
    }
};
