class Solution {
public:
    vector<vector<int>> dp;
    bool isSame(char a, char b){
        return b=='.' || a==b;
    }
    bool solve(string &s, string &p, int i, int j){
        // cout<<i<<" "<<j<<endl;
        if(i<0 && j<0) return true;
        else if(j<0) return false;

        if(dp[i+1][j] != -1) return dp[i+1][j];

        bool ans = false;
        if(i>=0 && isSame(s[i], p[j])) ans = solve(s, p, i-1, j-1);
        else if(j>0 && p[j]=='*'){
            if(i >= 0 && isSame(s[i], p[j-1]))
                ans = solve(s, p, i, j-2) || solve(s, p, i-1, j);
            else
                ans = solve(s, p, i, j-2);
        }else ans = false;

        return dp[i+1][j] = ans;
    }
    bool isMatch(string s, string p) {
        dp.assign(s.size()+1, vector<int> (p.size(), -1));
        return solve(s, p, s.size()-1, p.size()-1);
    }
};
