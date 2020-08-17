# Solution based off one from @rock

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        const auto rows{static_cast<int>(mat.size())};
        const auto columns{static_cast<int>(mat[0].size())};
        vector<vector<int>> output;
        vector<vector<int>> dp;
        
        for (auto i{0}; i < rows; i++) {
            output.emplace_back(vector<int>(columns));   
        }
        
        for (auto i{0}; i < rows + 1; i++) {
            dp.emplace_back(vector<int>(columns + 1));
        }
        
        for (auto i{0}; i < rows; i++) {
            for (auto j{0}; j < columns; j++) {
                dp[i + 1][j + 1] = mat[i][j] + dp[i][j + 1] + dp[i + 1][j] - dp[i][j];
            }
        }
        
        for (const auto r: dp) {
            for (const auto c: r) {
                cout << c << ' ';
            }
            cout << endl;
        }
        
        for (auto i{0}; i < rows; i++) {
            for (auto j{0}; j < columns; j++) {
                auto sum{0};
                const auto r1{max(i - K, 0)};
                const auto r2{min(i + K + 1, rows)};
                const auto c1{max(j - K, 0)};
                const auto c2{min(j + K + 1, columns)};
                
                output[i][j] = dp[r1][c1] - dp[r1][c2] - dp[r2][c1] + dp[r2][c2];
            }
        }
        
        return output;
    }
};
