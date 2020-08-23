class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        auto count{0};
        const auto rows{static_cast<int>(grid.size())};
        const auto cols{static_cast<int>(grid[0].size())};
        
        auto i{0};
        for (; i < rows && grid[i][0] >= 0; i++) {
            for (auto j{0}; j < cols; j++) {
                if (grid[i][j] < 0) {
                    count++;
                }
            }
        }
        
        count += (rows - i) * cols;
        
        return count;
    }
};
