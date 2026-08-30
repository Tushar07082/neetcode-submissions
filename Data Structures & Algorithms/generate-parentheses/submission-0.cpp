class Solution {
public:
    void genParen(vector<string> &ans, string &s, int n, int openingDone, int closingDone){
        if(closingDone == n) {
            ans.push_back(s);
            return;
        }
        if(openingDone < n){
            s.push_back('(');
            genParen(ans, s, n, openingDone+1, closingDone);
            s.pop_back();
        }

        if(closingDone < openingDone){
            s.push_back(')');
            genParen(ans, s, n, openingDone, closingDone+1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        int openingDone = 0, closingDone = 0;
        vector<string> ans;
        genParen(ans, s, n, openingDone, closingDone);
        return ans;
    }
};