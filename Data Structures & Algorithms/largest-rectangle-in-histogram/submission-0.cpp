class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> nse(n,n);
        vector<int> pse(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            }
            st.push(i);
        }
        st = stack<int> ();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i] = st.top();
            }
            st.push(i);
        }

        // for(int i=0;i<n;i++){
        //     cout<<nse[i]<<" ";
        // }
        // cout<<endl;

        // for(int i=0;i<n;i++){
        //     cout<<pse[i]<<" ";
        // }
        // cout<<endl;

        int ans = 0;
        for(int i=0;i<n;i++){
            ans =  max(ans, heights[i] * (nse[i]-pse[i]-1));
        }
        return ans;
    }
};
