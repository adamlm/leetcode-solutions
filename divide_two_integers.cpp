class Solution {
public:
    int divide(int dividend, int divisor) {
        auto negative{(dividend >> 31) != (divisor >> 31)};
        auto quotient{0};
        auto remainder{0};
        auto extra{0};

        if (divisor == INT_MIN && dividend != INT_MIN) {
            return 0;
        } else if (divisor == INT_MIN && dividend == INT_MIN) {
            return 1;
        }
        
        divisor = abs(divisor);
        
        if (dividend == INT_MIN) {
            dividend += divisor;
            extra = 1;
        }
        
        dividend = abs(dividend);
        
        for (auto i{31}; i >= 0; i--) {
            remainder <<= 1;
            remainder |= 0x01 & (dividend >> i);
            
            if (remainder >= divisor) {
                remainder -= divisor;
                quotient |= 0x01 << i;
            }
        }
        
        if (0 - quotient - extra == INT_MIN) {
            return negative? INT_MIN : INT_MAX;
        }
        
        return negative? 0 - quotient - extra : quotient + extra;
    }
};
