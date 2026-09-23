class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int> &prices, int i, bool holding){
        if(i>=prices.size()) return 0;
        if(dp[i][holding]!= -1) return dp[i][holding];
        if(holding){
            return  dp[i][holding] = max(solve(prices, i+1, holding) , prices[i]+ solve(prices, i+2, !holding));
        }else{
            return  dp[i][holding] = max(solve(prices, i+1, holding), solve(prices, i+1, !holding) - prices[i]);
        }
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(), vector<int> (2, -1));
        return solve(prices, 0, false);
    }
};
