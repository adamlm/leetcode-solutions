class Solution {
public:
    int countBattleships(const vector<vector<char>>& board) {
        auto count{0};

        for (auto row{0}; row < std::size(board); ++row) {
            for (auto col{0}; col < std::size(board[0]); ++col) {
                if (row > 0 && board[row - 1][col] == 'X') {
                    continue;
                }

                if (col > 0 && board[row][col - 1] == 'X') {
                    continue;
                }

                if (board[row][col] == 'X') {
                    count++;
                }
            }
        }

        return count;
    }
};

