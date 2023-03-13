#include <unordered_set>

auto getPossibleNums(const vector<vector<char>>& board, std::size_t i, std::size_t j) -> std::vector<char> {
    std::unordered_set<char> possible_nums{'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (auto idx{0}; idx < 9; ++idx) {
        const auto num = board[idx][j];
        if (possible_nums.count(num) != 0) {
            possible_nums.erase(num);
        }
    }

    for (auto jdx{0}; jdx < 9; ++jdx) {
        const auto num = board[i][jdx];
        if (possible_nums.count(num) != 0) {
            possible_nums.erase(num);
        }
    }

    const auto box_row_start = (i / 3) * 3;
    const auto box_col_start = (j / 3) * 3;
    for (auto idx{box_row_start}; idx < box_row_start + 3; ++idx) {
        for (auto jdx{box_col_start}; jdx < box_col_start + 3; ++jdx) {
            const auto num = board[idx][jdx];
            if (possible_nums.count(num) != 0) {
                possible_nums.erase(num);
            }
        }
    }

    std::vector<char> nums_vec;
    nums_vec.insert(std::cbegin(nums_vec), std::cbegin(possible_nums), std::cend(possible_nums));
    return nums_vec;
}


auto getNextCoords(std::size_t i, std::size_t j) -> std::tuple<std::size_t, std::size_t> {
    if (i == 8 && j == 8) {
        return {9, 9};
    }

    if (j == 8) {
        return {i + 1, 0};
    }

    return {i, j + 1};
}

auto backtrack(vector<vector<char>>& board, std::size_t i, std::size_t j) -> bool {
    const auto coords = getNextCoords(i, j);
    const auto next_i = std::get<0>(coords);
    const auto next_j = std::get<1>(coords);

    if (i == 9 && j == 9) {
        return true;
    }

    if (board[i][j] != '.') {
        return backtrack(board, next_i, next_j);
    }

    const auto possible_nums = getPossibleNums(board, i, j);
    for (auto n{0}; n < std::size(possible_nums); ++n) {
        board[i][j] = possible_nums[n];
        if (backtrack(board, next_i, next_j)) {
            return true;
        }
        board[i][j] = '.';
    }

    return false;
}

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
};

