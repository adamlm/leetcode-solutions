class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        auto count{0};
        const auto rows{static_cast<int>(grid.size())};
        const auto cols{static_cast<int>(grid[0].size())};
        
        auto i{0};
        for (; i < rows && grid[i][0] >= 0; i++) {
            auto left{0};
            auto right{cols - 1};
            
            while (left <= right) {
                const auto mid{(left + right) / 2};
                
                if (grid[i][mid] >= 0) {
                    left = mid + 1;
                } else if (mid == 0 || grid[i][mid - 1] >= 0) {
                    count += cols - mid;
                    break;
                } else {
                    right = mid;
                }
            }
        }
        
        count += (rows - i) * cols;
        
        return count;
    }
};
