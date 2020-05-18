class Solution {
public:
    int sumSquare(int n) {
        auto sum{0};
        
        while (n > 0) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        
        return sum;
    }
    
    bool isHappy(int n) {        
        auto tortoise = sumSquare(n);
        auto hare = sumSquare(sumSquare(n));
        
        if (tortoise == 1 || hare == 1) {
            return true;
        }
        
        while (tortoise != hare) {
            tortoise = sumSquare(tortoise);
            hare = sumSquare(sumSquare(hare));
            
            if (tortoise == 1 || hare == 1) {
                return true;
            }
        }
        
        return false;
    }
};
