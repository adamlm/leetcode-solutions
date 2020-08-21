class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> output(A.size(), 0);
        auto left{A.begin()};
        auto right{A.end() - 1};
        
        for (auto i{static_cast<int>(output.size()) - 1}; i >= 0; i--) {
            const auto lVal{pow(*left, 2)};
            const auto rVal{pow(*right, 2)};
            
            output[i] = max(lVal, rVal);
            
            if (lVal > rVal) {
                left++;
            } else {
                right--;
            }
        }
        
        return output;
    }
};
