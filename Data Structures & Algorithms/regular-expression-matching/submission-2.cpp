class Solution {
public:
    bool isSame(char a, char b){
        return b=='.' || a==b;
    }
    bool solve(string &s, string &p, int i, int j){
        // cout<<i<<" "<<j<<endl;
        if(i<0 && j<0) return true;
        else if(j<0) return false;

        bool ans = false;
        if(i>=0 && isSame(s[i], p[j])) ans = solve(s, p, i-1, j-1);
        else if(j>0 && p[j]=='*'){
            ans = ans || solve(s, p, i, j-2);
            while(i>=0 && isSame(s[i], p[j-1])) {
                ans = ans || solve(s, p, i-1, j-2);
                i--;
            } 
        }else ans = false;

        return ans;
    }
    bool isMatch(string s, string p) {
        return solve(s, p, s.size()-1, p.size()-1);
    }
};
