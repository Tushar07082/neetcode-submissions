class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ans = 0, n = position.size();
        vector<pair<int,double>> vp;
        for(int i=0;i<n;i++){
            double time = (target- position[i])/(double) speed[i];
            vp.push_back({position[i], time});
        }
        sort(vp.begin(),vp.end());
        double maxTimeTillNow = 0;
        for(int i=n-1;i>=0;i--){ 
            if(vp[i].second > maxTimeTillNow){
                maxTimeTillNow= vp[i].second;
                ans++;
            }
        }
        return ans;
    }
};
