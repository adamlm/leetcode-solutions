class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<unordered_set<char>, 9> rows;
        array<unordered_set<char>, 9> cols;
        array<unordered_set<char>, 9> cells;
        
        for (int i{0}; i < 9; ++i) {
            for (int j{0}; j < 9; ++j) {
                const auto ch = board[i][j];
                
                if (ch == '.') {
                    continue;
                }
                
                if (rows[i].count(ch) != 0 ||
                    cols[j].count(ch) != 0 ||
                    cells[3 * (i / 3) + j / 3].count(ch) != 0) {
                    return false;
                }
                
                rows[i].insert(ch);
                cols[j].insert(ch);
                cells[3 * (i / 3) + j / 3].insert(ch);
            }
        }
        
        return true;
    }
};
