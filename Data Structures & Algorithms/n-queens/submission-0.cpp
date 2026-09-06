class Solution {
public:
    unordered_map<int,int> colsDone;
    unordered_map<int,int> backDiagDone;
    unordered_map<int,int> frontDiagDone;
    void findSols(vector<vector<string>> &ans, vector<string> &curr, int i){
        if(i>=curr.size()){
            ans.push_back(curr);
            return;
        }

        for(int j=0;j<curr.size();j++){
            // cout<<i<<" "<<j<<" "<<colsDone[j]<<" "<<backDiagDone[i-j]<<" "<<frontDiagDone[i+j]<<endl;
            if(colsDone[j] == 0 && backDiagDone[i-j] == 0 && frontDiagDone[i+j] == 0){
                // cout<<i<<" "<<j<<endl;
                curr[i][j] = 'Q';
                colsDone[j]  = 1;
                backDiagDone[i-j] = 1;
                frontDiagDone[i+j] = 1;
                findSols(ans, curr, i+1);
                curr[i][j] = '.';
                colsDone[j]  = 0;
                backDiagDone[i-j] = 0;
                frontDiagDone[i+j] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        int row=0, col=0;
        vector<vector<string>> ans;
        vector<string> curr(n, "");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                curr[i] += ".";
            }
        }
        findSols(ans, curr, 0);
        return ans;
    }
};
