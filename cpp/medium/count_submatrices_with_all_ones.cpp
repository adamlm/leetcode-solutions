class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        const auto M{mat.size()};
        const auto N{mat[0].size()};
        auto result{0};
        
        for (auto startRow{0}; startRow < M; startRow++) {
            vector<int> compressedMatrix(N, 1);
            
            for (auto iRow{startRow}; iRow < M; iRow++) {
                for (auto k{0}; k < N; k++) {
                    compressedMatrix[k] &= mat[iRow][k];
                }
                
                result += helper(compressedMatrix);
            }
        }
        
        return result;
    }
    
    int helper(vector<int>& row) {
        auto count{0};
        auto result{0};
        
        for(const auto e: row) {
            count = e == 1? count + 1: 0;
            result += count;
        }
        
        return result;
    }
};
