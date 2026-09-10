class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        vector<vector<bool>> dp(n, vector<bool> (n,false));

        for(int i=0;i<n;i++){
            dp[i][i] = true;
            ans++;
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]!=s[j]) dp[i][j] = false;
                else if(j==i+1) dp[i][j] = true;
                else if(dp[i+1][j-1] != 0){
                    dp[i][j] = true;
                }else{
                    dp[i][j] = false;
                }

                if(dp[i][j] != false){
                    ans++;
                }
            }
        }
        return ans;
    }
};
