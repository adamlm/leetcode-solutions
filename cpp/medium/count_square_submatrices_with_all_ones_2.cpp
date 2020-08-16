# Implementation based on lee215

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const auto rows{matrix.size()};
        const auto columns{matrix[0].size()};
        auto count{0};
        
        for (auto i{0}; i < rows; i++) {
            for (auto j{0}; j < columns; j++) {
                if (matrix[i][j] > 0 && i > 0 && j > 0) {
                    matrix[i][j] = min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1])) + 1;
                }
                
                count += matrix[i][j];
            }
        }
        
        return count;
    }
};
