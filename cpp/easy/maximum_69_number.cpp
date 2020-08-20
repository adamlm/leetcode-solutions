class Solution {
public:
    int maximum69Number (int num) {
        int digits[4];
        
        for (auto i{0}; i < 4; i++) {
            digits[i] = num % 10;
            num /= 10;
        }
        
        for (auto i{3}; i >= 0; i--) {
            if (digits[i] == 6) {
                digits[i] = 9;
                break;
            }
        }
        
        return digits[3] * 1000 + digits[2] * 100 + digits[1] * 10 + digits[0];
    }
};
