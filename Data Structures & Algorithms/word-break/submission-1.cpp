class Solution {
public:
    bool doWordsExist(string &s, int start, unordered_set<string> &dict, vector<int> &dp){
        int n = s.size();
        if(start>=n) return true;
        if(dp[start] != -1) return dp[start];

        string curr = "";
        bool ans = false;
        for(int i=start;i<n;i++){
            curr += s[i];
            ans = ans || (dict.count(curr) && doWordsExist(s, i+1, dict, dp));
        }
        return dp[start] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return doWordsExist(s, 0, dict, dp);
    }
};
