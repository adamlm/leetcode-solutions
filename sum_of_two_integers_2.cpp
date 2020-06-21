class Solution {
public:
    int getSum(int a, int b) {
        auto sum{0};
        auto carry{0};
        
        for (auto i{0}; i < 32; i++) {
            const auto aBit{(a >> i) & 1};
            const auto bBit{(b >> i) & 1};
            
            sum |= (aBit ^ bBit ^ carry) << i;
            carry = (aBit & bBit) | (bBit & carry) | (aBit & carry);
        }
        
        return sum;
    }
};
