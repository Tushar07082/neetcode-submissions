class Solution {
public:
    bool doesWordExist(vector<vector<char>> &board, string word, int i, int j, int x, vector<vector<bool>> visited){
        if(x==word.size()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] != word[x] || visited[i][j] == true) return false;

        visited[i][j] = true;
        return doesWordExist(board, word, i+1, j, x+1, visited) || doesWordExist(board, word, i-1, j, x+1, visited) || doesWordExist(board, word, i, j-1, x+1, visited) || doesWordExist(board, word, i, j+1, x+1, visited);
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && doesWordExist(board, word, i, j, 0, visited)) return true;
            }
        }
        return false;
    }
};
