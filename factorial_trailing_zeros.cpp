class Solution {
public:
    int trailingZeroes(int n) {
        auto zeros{0};
        
        while (n / 5 > 0) {
            auto tmp{n / 5};
            zeros += tmp;
            n = tmp;
        }
        
        return zeros;
    }
};
