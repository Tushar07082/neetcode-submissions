class Solution {
public:
    double findDistToOrigin(int x, int y){
        return sqrt(x*x + y*y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>, vector<pair<double, int>> , greater<pair<double,int>>> pq;
        int n = points.size();
        for(int i=0;i<n;i++){
            pq.push({findDistToOrigin(points[i][0], points[i][1]), i});
        }
        vector<vector<int>> ans;
        while(k--){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
