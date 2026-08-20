class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<vector<unordered_set<char>>> box(3 , vector<unordered_set<char>>(3));

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char elem = board[i][j];
                if(elem != '.'){
                    if(rows[i].find(elem) != rows[i].end() || cols[j].find(elem) != cols[j].end() || box[i/3][j/3].find(elem) != box[i/3][j/3].end()){
                        cout<<i<<" "<<j<<" "<<elem<<endl;
                        return false;
                    }else{
                        rows[i].insert(elem);
                        cols[j].insert(elem);
                        box[i/3][j/3].insert(elem);
                    }
                }
            }
        }
        return true;
    }
};
