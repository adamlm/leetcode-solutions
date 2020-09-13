class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const auto rows{static_cast<int>(grid.size())};
        const auto cols{static_cast<int>(grid[0].size())};
        auto p{0};
        
        for (auto i{0}; i < rows; i++) {
            for (auto j{0}; j < cols; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                
                if (j == 0 || grid[i][j - 1] == 0) {
                    p++;
                }
                
                if (j == cols - 1 || grid[i][j + 1] == 0) {
                    p++;
                }
                
                if (i == 0 || grid[i - 1][j] == 0) {
                    p++;
                }
                
                if (i == rows - 1 || grid[i + 1][j] == 0) {
                    p++;
                }
            }
        }
        
        return p;
    }
};
