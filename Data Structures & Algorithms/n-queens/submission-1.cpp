class Solution {
public:
    unordered_set<int> colsDone;
    unordered_set<int> backDiagDone;
    unordered_set<int> frontDiagDone;
    void findSols(vector<vector<string>> &ans, vector<string> &curr, int i){
        if(i==curr.size()){
            ans.push_back(curr);
            return;
        }

        for(int j=0;j<curr.size();j++){
            // cout<<i<<" "<<j<<" "<<colsDone[j]<<" "<<backDiagDone[i-j]<<" "<<frontDiagDone[i+j]<<endl;
            if(colsDone.count(j) == 0 && backDiagDone.count(i-j) == 0 && frontDiagDone.count(i+j) == 0){
                // cout<<i<<" "<<j<<endl;
                curr[i][j] = 'Q';
                colsDone.insert(j);
                backDiagDone.insert(i-j);
                frontDiagDone.insert(i+j);
                findSols(ans, curr, i+1);
                curr[i][j] = '.';
                colsDone.erase(j);
                backDiagDone.erase(i-j);
                frontDiagDone.erase(i+j);
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
