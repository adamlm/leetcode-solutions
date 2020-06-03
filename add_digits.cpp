class Solution {
public:
    int addDigits(int num) {
        auto sum{num};
        
        while (sum > 9) {
            sum = 0;
            
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            
            num = sum;
        }
        
        return sum;
    }
};
