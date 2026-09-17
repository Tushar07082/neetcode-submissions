class Solution {
public:
    vector<vector<int>> dp;
    int solve(int amount, vector<int> &coins, int i){
        if(amount == 0) return 1;
        if(i<0) return 0;
        if(dp[amount][i] != -1) return dp[amount][i];

        int ans = 0;
        if(amount >= coins[i]){
            ans += solve(amount-coins[i], coins, i);
        }
        ans += solve(amount, coins, i-1);
        return dp[amount][i] = ans;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(amount+1, vector<int> (n+1, -1));
        return solve(amount, coins, n-1);
    }
};
