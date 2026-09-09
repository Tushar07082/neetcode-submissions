class Solution {
public:
    bool isPalindrome(string x){
        int n = x.size();
        for(int i=0;i<n/2;i++){
            if(x[i] != x[n-1-i]) return false;
        }
        return true;
    }
    void findSplits(string &s, vector<vector<string>> &ans, vector<string> &curr, int start){
        int n = s.size();
        if(start==n){
            ans.push_back(curr);
            return;
        }
        string x = "";

        for(int i=start;i<s.size();i++){
            x += s[i];
            if(isPalindrome(x)){
                curr.push_back(x);
                findSplits(s, ans, curr, i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        findSplits(s, ans, curr, 0);
        return ans;
    }
};
