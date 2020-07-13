class Solution {
public:
    int hammingDistance(int x, int y) {
        auto distance{0};
        auto exor{x ^ y};
        
        while (exor > 0) {
            distance += exor & 0x01;
            exor >>= 1;
        }
        
        return distance;
    }
};
