class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &s, string &t, int i, int j){
        if(j>=t.size()) return 1;
        if(i>=s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        dp[i][j] = solve(s, t, i+1, j);
        if(s[i]==t[j]) dp[i][j] += solve(s, t, i+1, j+1);

        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        dp.assign(n+1, vector<int> (m+1, 0));

        for(int i=0;i<=n;i++){
            dp[i][m] = 1;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                dp[i][j] = dp[i+1][j];
                if(s[i]==t[j]){
                    dp[i][j] += dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};
