class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &word1, string &word2, int n, int m){
        if(m<0 && n<0) return 0;
        if(m<0 || n<0) return max(m, n) + 1;
        if(dp[n][m] != -1) return dp[n][m];
        if(word1[n] == word2[m]) return dp[n][m] = solve(word1, word2, n-1, m-1);
        else return dp[n][m] = 1 + min({solve(word1, word2, n-1, m), solve(word1, word2, n, m-1), solve(word1, word2, n-1, m-1)});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        dp.assign(n, vector<int> (m, -1));
        return solve(word1, word2, n-1, m-1);
    }
};
