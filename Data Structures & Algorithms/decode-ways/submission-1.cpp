class Solution {
public:
    int solve(string s, int i){
        if(i>=s.size()) return 1;
        if(s[i]=='0') return 0;
        if(s[i]=='1') return solve(s, i+1) + solve(s, i+2);
        if(s[i]=='2' && i<s.size()-1 && s[i+1] <= '6') return solve(s, i+1) + solve(s, i+2);
        else return solve(s, i+1);
    }
    int numDecodings(string s) {
        int n = s.size();
        int afterOneStep = 1, afterTwoSteps = 0;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                afterTwoSteps = afterOneStep;
                afterOneStep = 0;
            }else{
                int curr;
                if(s[i]=='1' || (s[i]=='2' && i<s.size()-1 && s[i+1] <= '6')){
                    curr = afterOneStep + afterTwoSteps;
                }else {
                    curr = afterOneStep;
                }
                afterTwoSteps = afterOneStep;
                afterOneStep = curr;
            }

        }
        return afterOneStep;
    }
};
