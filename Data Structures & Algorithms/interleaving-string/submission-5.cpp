class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string s1, string s2, string s3, int i, int j, int k){
        if(k==0 && i==0 && j==0) return true;
        else if(k==0) return false;

        if(dp[i][j] != -1) return dp[i][j];

        bool ans = false;

        if(i>0 && s1[i-1]==s3[k-1]){
            ans = ans || solve(s1, s2, s3, i-1, j, k-1);
        }
        if(ans) return dp[i][j] = ans;

        if(j>0 && s2[j-1]==s3[k-1]){
            ans = ans || solve(s1, s2, s3, i, j-1, k-1);
        }
        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int x = s1.size(), y = s2.size(), z = s3.size();
        if (x + y != s3.size()) {
            return false;
        }
        if(x==0) return s2==s3;
        if(y==0) return s1==s3;
        dp.assign(x+1, vector<int> (y+1, -1));
        return solve(s1, s2, s3, x, y, z);
    }
};
