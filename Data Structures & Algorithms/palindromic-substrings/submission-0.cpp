class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        vector<vector<int>> dp(n, vector<int> (n, -1));

        for(int i=0;i<n;i++){
            dp[i][i] = 1;
            ans++;
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]!=s[j]) dp[i][j] = 0;
                else if(j==i+1) dp[i][j] = 2;
                else if(dp[i+1][j-1] != 0){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }else{
                    dp[i][j] = 0;
                }

                if(dp[i][j] != 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};
