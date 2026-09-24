class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>> &matrix, int i, int j, int last){
        if(i<0 || j<0 || i>=matrix.size() || j>= matrix[0].size() || matrix[i][j] <= last){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = 1 + max({
            solve(matrix, i+1, j, matrix[i][j]),
            solve(matrix, i-1, j, matrix[i][j]),
            solve(matrix, i, j+1, matrix[i][j]),
            solve(matrix, i, j-1, matrix[i][j])
        });
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 1, n = matrix.size(), m= matrix[0].size();
        dp.resize(n, vector<int> (m, -1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans, solve(matrix, i, j, -1));
            }
        }
        return ans;
    }
};
