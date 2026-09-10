class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        int maxI = 0, maxJ = 0;

        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]!=s[j]) dp[i][j] = 0;
                else if(j==i+1) dp[i][j] = 2;
                else if(dp[i+1][j-1] != 0){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }else{
                    dp[i][j] = 0;
                }

                if(dp[i][j] > maxJ-maxI+1){
                    maxI = i;
                    maxJ = j;
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // [1, -1, -1, -1]
        // [-1, 1, 2, -1]
        // [-1, -1, 1, 0]
        // [-1, -1, -1, 1]
        return s.substr(maxI, maxJ-maxI+1);
    }
};
