auto sinkShip(std::vector<std::vector<char>>& board, std::size_t row, std::size_t col) {
    if (row >= std::size(board) || col >= std::size(board[0])) {
        return;
    }

    if (board[row][col] == '.') {
        return;
    }

    board[row][col] = '.';
    sinkShip(board, row + 1, col);
    sinkShip(board, row, col + 1);
}

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        auto count{0};

        for (auto row{0}; row < std::size(board); ++row) {
            for (auto col{0}; col < std::size(board[0]); ++col) {
                if (board[row][col] == 'X') {
                    count++;
                    sinkShip(board, row, col);
                }
            }
        }

        return count;
    }
};

