class Solution {
public:
    int arrangeCoins(int n) {
        long left{0};
        long right{n};
        
        while (left <= right) {
            const long k = (left + right) / 2;
            const long val = k * (k + 1) / 2;
            
            if (val == n) {
                return k;
            }
            
            if (val > n) {
                right = k - 1;
            } else {
                left = k + 1;
            }
        }
        
        return right;
    }
};
