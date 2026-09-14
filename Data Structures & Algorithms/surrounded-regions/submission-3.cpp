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
        
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                markInvalid(board, i, 0);
            }

            if (board[i][m - 1] == 'O') {
                markInvalid(board, i, m - 1);
            }
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                markInvalid(board, 0, j);
            }

            if (board[n - 1][j] == 'O') {
                markInvalid(board, n - 1, j);
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
