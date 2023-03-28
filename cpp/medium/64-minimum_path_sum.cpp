#include <algorithm>

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const auto rows{std::size(grid)};
        const auto cols{std::size(grid[0])};

        std::vector<std::vector<int>> dp(rows, std::vector(cols, 0));
        dp[0][0] = grid[0][0];

        for (auto i{0}; i < rows; ++i) {
            for (auto j{0}; j < cols; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }

                auto left_sum{100000};
                if (i > 0) {
                    left_sum = dp[i - 1][j];
                }

                auto upper_sum{100000};
                if (j > 0) {
                    upper_sum = dp[i][j - 1];
                }

                dp[i][j] = std::min(left_sum, upper_sum) + grid[i][j];
            }
        }

        return dp[rows - 1][cols - 1];
    }
};

