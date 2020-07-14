class Solution {
public:
    int hammingDistance(int x, int y) {
        auto distance{0};
        
        for (auto i{0}; i < 32; i++) {
            if ((x & 0x01) != (y & 0x01)) {
                distance++;
            }
            
            x >>= 1;
            y >>= 1;
        }
        
        return distance;
    }
};
