class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int,int>, unordered_set<char>>boxs;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c = board[i][j];
                if(c == '.'){
                    continue;
                }
                pair<int,int> box_idx = {i/3, j/3};
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
