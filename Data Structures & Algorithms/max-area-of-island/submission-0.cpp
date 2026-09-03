class Solution {
public:
    int markAllPoints(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &grid){
        if(i<0 || j<0 || i>= grid.size()|| j>= grid[0].size() || grid[i][j]==0 || visited[i][j]) return 0;
        
        visited[i][j] = true;
        int ans = 1;
        ans += markAllPoints(i+1, j, visited, grid);
        ans += markAllPoints(i-1, j, visited, grid);
        ans += markAllPoints(i, j+1, visited, grid);
        ans += markAllPoints(i, j-1, visited, grid);
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    ans = max(ans, markAllPoints(i,j, visited, grid));
                }
            }
        }
        return ans;
    }
};
