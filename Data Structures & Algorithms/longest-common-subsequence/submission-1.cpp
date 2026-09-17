class Solution {
    vector<vector<int>> dp;
public:
    int lcs(string &text1, string text2, int i, int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(text1[i] == text2[j]){
            ans = max(ans, 1+ lcs(text1, text2, i-1, j-1));
        }
        ans = max({ans, lcs(text1, text2, i, j-1), lcs(text1, text2, i-1, j)});
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        dp.resize(n+1, vector<int> (m+1, -1));

        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                    continue;
                }
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = max(dp[i][j], 1 + dp[i-1][j-1]);
                }
                dp[i][j] = max ({dp[i][j], dp[i-1][j], dp[i][j-1]});
            }
        }
        return dp[n][m];
    }
};
