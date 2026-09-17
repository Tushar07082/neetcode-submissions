class Solution {
public:
    int dfs(int m, int n, vector<vector<int>> &dp){
        if(m<0 || n<0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        return dp[m][n] = dfs(m, n-1, dp) + dfs(m-1, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        dp[0][0] = 1;
        return dfs(m-1, n-1, dp);
    }
};
