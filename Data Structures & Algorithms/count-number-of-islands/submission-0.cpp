class Solution {
public:
    void markAllPoints(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &grid){
        if(i<0 || j<0 || i>= grid.size()|| j>= grid[0].size() || grid[i][j]=='0' || visited[i][j]) return;
        
        visited[i][j] = true;
        markAllPoints(i+1, j, visited, grid);
        markAllPoints(i-1, j, visited, grid);
        markAllPoints(i, j+1, visited, grid);
        markAllPoints(i, j-1, visited, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    markAllPoints(i,j, visited, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
