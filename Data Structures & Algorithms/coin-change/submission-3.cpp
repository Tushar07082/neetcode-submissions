class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, 1000000);

        dp[0] = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=amount;j++){
                if(coins[i]<=j){
                    dp[j] = min(1+ dp[j-coins[i]], dp[j]);
                }
            }
        }
        return dp[amount] == 1000000 ? -1 : dp[amount];
    }
};
