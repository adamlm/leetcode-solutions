class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        auto sum{0};
        
        auto zeros{0};
        auto ones{0};
        for (auto i{0}; i < 32; ++i) {
            zeros = 0;
            ones = 0;
            
            for (auto &n: nums) {
                n & 0x1? ++ones: ++zeros;
                n >>= 1;
            }
            
            sum += ones * zeros;
        }
        
        return sum;
    }
};
