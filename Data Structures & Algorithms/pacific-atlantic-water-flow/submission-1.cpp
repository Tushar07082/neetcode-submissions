class Solution {
public:
    void pushAll(unordered_set<string> &ocean, int i, int j, vector<vector<int>> &heights, int last){
        if(i<0 || j<0 || i>=heights.size() || j>= heights[0].size() || heights[i][j] < last || ocean.find(to_string(i) + " " + to_string(j)) != ocean.end()){
            return;
        }
        ocean.insert(to_string(i) + " " + to_string(j));
        last = heights[i][j];

        pushAll(ocean, i+1, j, heights, last);
        pushAll(ocean, i-1, j, heights, last);
        pushAll(ocean, i, j+1, heights, last);
        pushAll(ocean, i, j-1, heights, last);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        unordered_set<string> pacific;
        unordered_set<string> atlantic;
        for(int i=0;i<n;i++){
            pushAll(pacific, i, 0, heights, 0);
            pushAll(atlantic,i, m-1, heights, 0);
        }
        for(int j=0;j<m;j++){
            pushAll(pacific, 0, j, heights, 0);
            pushAll(atlantic,n-1, j, heights, 0);
        }

        vector<vector<int>> ans;
        for(auto cell: pacific){
            if(atlantic.find(cell) != atlantic.end()){
                int separator = cell.find(' ');

                int i = stoi(cell.substr(0, separator));
                int j = stoi(cell.substr(separator + 1));

                ans.push_back({i, j});
            }
        }
        return ans;
        
        
    }
};
