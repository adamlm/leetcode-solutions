class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }
        
        auto lower{1};
        long upper{num};
        
        while (lower < upper) {
            const auto mid{(lower + upper) / 2};
            const long square{mid * mid};
            
            if (square == num) {
                return true;
            }
            
            if (square > num) {
                upper = mid;
            } else {
                lower = mid + 1;
            }
        }
        
        return false;
    }
};
