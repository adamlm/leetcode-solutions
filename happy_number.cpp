class Solution {
public:
    bool isHappy(int n) {
        auto sum{0};
        
        while (n > 0) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        
        if (sum == 89) {
            return false;
        }
        
        return sum == 1? true: isHappy(sum);
    }
};
