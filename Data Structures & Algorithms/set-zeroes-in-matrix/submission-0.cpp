class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<bool> isRowZero(n, false);
        vector<bool> isColZero(m, false);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    isRowZero[i] = true;
                    isColZero[j] = true;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isRowZero[i] || isColZero[j]) matrix[i][j] = 0;
            }
        }
    }
};
