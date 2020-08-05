class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        const auto n{static_cast<int>(grid.size())};
        vector<int> positions;
        auto moves{0};
        
        for (auto i{0}; i < n; i++) {
            int zeros{0};
            
            for (auto j{n - 1}; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    zeros++;
                } else {
                    break;
                }
            }
            
            positions.push_back(zeros);
        }
        
        for (auto i{0}; i < n; i++) {
            if (positions[i] < n - i - 1) {                
                auto j{i};
                
                while (j < n && positions[j] < n - i - 1) {
                    j++;
                }
                
                if (j == n) {
                    return -1;
                }
                
                while (j > i) {
                    swap(positions[j], positions[j - 1]);
                    moves++;
                    j--;
                }
            }
        }
        
        return moves;
    }
};
