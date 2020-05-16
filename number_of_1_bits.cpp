class Solution {
public:
    int hammingWeight(uint32_t n) {
        auto count{0};
        
        for (auto i{0}; i < 32; i++) {
            if (n == 0) {
                break;
            }
            count += (n & 1) == 1? 1: 0;
            n >>= 1;
        }
        
        return count;
    }
};
