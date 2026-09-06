class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int freshFruits = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    freshFruits++;
                }
            }
        }
        if(freshFruits==0) return 0;
        int ans = -1;
        while(!q.empty()){
            ans++;
            int p = q.size();
            for(int i=0;i<p;i++){
                auto[x, y] = q.front(); q.pop();
                if(x > 0 && grid[x-1][y] == 1){
                    freshFruits--;
                    grid[x-1][y] = 2;
                    q.push({x-1, y});
                }
                if(x < n-1 && grid[x+1][y] == 1){
                    freshFruits--;
                    grid[x+1][y] = 2;
                    q.push({x+1, y});
                }
                if(y > 0 && grid[x][y-1] == 1){
                    freshFruits--;
                    grid[x][y-1] = 2;
                    q.push({x, y-1});
                }
                if(y < m-1 && grid[x][y+1] == 1){
                    freshFruits--;
                    grid[x][y+1] = 2;
                    q.push({x, y+1});
                }
            }
        }
        return freshFruits==0 ? ans : -1;
    }
};
