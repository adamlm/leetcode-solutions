class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const auto rows{matrix.size()};
        const auto columns{matrix[0].size()};
        auto total{0};
        
        for (auto i{0}; i < rows; i++) {
            vector<int> summary = matrix[i];
            
            for (auto j{i}; j < rows; j++) {
                auto count{0};
                
                for (auto k{0}; k < columns; k++) {
                    summary[k] &= matrix[j][k];
                    count = summary[k]? count + 1: 0;
                    
                    if (count == (j - i + 1)) {
                        total++;
                        count--;
                    }
                }
            }
        }
        
        return total;
    }
};
