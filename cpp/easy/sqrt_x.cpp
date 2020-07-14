class Solution {
public:
    int mySqrt(int x) {
        auto i{1};
        
        if (x == 0) {
            return 0;
        }
        
        while (x / i >= i) {
            i++;
        }
        
        return i - 1;
    }
};
