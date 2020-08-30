class Solution {
public:
    bool hasAlternatingBits(int n) {
        auto prev{n & 0x01};
        n >>= 1;
        
        while (n > 0) {
            const auto cur{n & 0x01};
            if (cur == prev) {
                return false;
            }
            
            prev = cur;
            n >>= 1;
        }
        
        return true;
    }
};
