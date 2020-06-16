class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) {
            return false;
        }
        
        const auto root{static_cast<int>(round(sqrt(num)))};
        
        return static_cast<long>(root) * root == num && 1073741824 % num == 0;
    }
};
