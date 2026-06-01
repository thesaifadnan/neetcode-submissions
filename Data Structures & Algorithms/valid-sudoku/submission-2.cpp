class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxs(9);

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c = board[i][j];
                if(c == '.'){
                    continue;
                }
                int box_idx = (i/3)*3 + (j/3);
                if(rows[i].count(c) || cols[j].count(c) || boxs[box_idx].count(c)){
                    return false;
                }else{
                    rows[i].insert(c);
                    cols[j].insert(c);
                    boxs[box_idx].insert(c);
                }
            }
        }
        return true;
    }
};
