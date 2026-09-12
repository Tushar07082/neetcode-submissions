class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(n+1, 1000000));

        for(int i=0;i<=n;i++) {
            dp[0][i] = 0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=amount;j++){
                if(coins[i]>j) dp[j][i] = dp[j][i+1];
                else{
                    dp[j][i] = min(1+ dp[j-coins[i]][i], dp[j][i+1]);
                }
            }
        }
        return dp[amount][0] == 1000000 ? -1 : dp[amount][0];
    }
};
