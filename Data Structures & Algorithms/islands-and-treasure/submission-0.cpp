class Solution {
public:
    void fillUpTheNeighbours(vector<vector<int>> &grid, int i, int j, int distance){
        queue<tuple<int,int,int>> q;
        q.push({i,j,0});
        while(!q.empty()){
            auto [x, y, z] = q.front(); q.pop();
            if(x>0 && grid[x-1][y] > z+1){
                grid[x-1][y] = z+1;
                q.push({x-1, y, z+1});
            }
            if(y>0 && grid[x][y-1] > z+1){
                grid[x][y-1] = z+1;
                q.push({x, y-1 , z+1});
            }
            if(x<grid.size()-1 && grid[x+1][y] > z+1){
                grid[x+1][y] = z+1;
                q.push({x+1, y, z+1});
            }
            if(y<grid[0].size()-1 && grid[x][y+1] > z+1){
                grid[x][y+1] = z+1;
                q.push({x, y+1, z+1});
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    fillUpTheNeighbours(grid, i, j, 0);
                }
            }
        }
    }
};
