class Solution {
public:
    int arrangeCoins(int n) {
        auto count{0};
        
        for (auto i{1}; i <= n; i++) {
            if (n - i >= 0) {
                count++;
                n -= i;
            }
        }
        
        return count;
    }
};
