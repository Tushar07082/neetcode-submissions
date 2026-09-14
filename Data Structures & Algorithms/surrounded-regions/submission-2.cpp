class Solution {
public:
    void markInvalid(vector<vector<char>> &board, int i, int j){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] =='I' || board[i][j] == 'X') return;

        board[i][j] = 'I';
        markInvalid(board, i+1, j);
        markInvalid(board, i-1, j);
        markInvalid(board, i, j-1);
        markInvalid(board, i, j+1);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j] == 'O'){
                    markInvalid(board, i, j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'I'){
                    board[i][j] = 'O';
                }else if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
