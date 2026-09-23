class Solution {
public:
    vector<unordered_map<int,int>> dp;
    int solve(vector<int> &prices, int i, int buyPrice){
        if(i>=prices.size()) return 0;
        auto it = dp[i].find(buyPrice);
        if(it != dp[i].end()) return dp[i][buyPrice];
        buyPrice = min(prices[i], buyPrice);
        return dp[i][buyPrice] = max(prices[i]-buyPrice + solve(prices, i+2, 1001), solve(prices, i+1, buyPrice));
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size());
        return solve(prices, 0, 1001);
    }
};
