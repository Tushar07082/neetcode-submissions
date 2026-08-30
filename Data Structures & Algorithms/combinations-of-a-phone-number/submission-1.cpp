class Solution {
public:
    void findCombinations(string &digits, string &curr, vector<string> &ans, int i, vector<string> &digitToLetter){
        if(i>=digits.size()){
            ans.push_back(curr);
            return;
        }
        for(auto j: digitToLetter[digits[i]-'0']){
            curr.push_back(j);
            findCombinations(digits, curr, ans, i+1, digitToLetter);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        vector<string> digitToLetter(10);
        int x = 0;
        for(int i=2;i<10;i++){
            int n = i==7 || i==9 ? 4 : 3;
            for(int j=0;j<n;j++){
                digitToLetter[i].push_back((char)(x+'a'));
                x++;
            }
        }
        vector<string> ans;
        string curr = "";
        findCombinations(digits, curr, ans, 0, digitToLetter);
        return ans;
    }
};
