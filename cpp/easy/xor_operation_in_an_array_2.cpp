class Solution {
public:
    int xorOperation(int n, int start) {
        auto exor{0};
        
        for (auto i{0}; i < n; i++) {
            exor ^= start + 2 * i;
        }
        
        return exor;
    }
};
