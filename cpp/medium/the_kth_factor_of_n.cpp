class Solution {
public:
    int kthFactor(int n, int k) {
        if (k == 1) {
            return 1;
        }
        
        auto output{-1};
        priority_queue<int, vector<int>, greater<int>> factors;
        const auto root{sqrt(n)};
        
        for (auto i{1}; i <= root; i++) {
            const auto quotient{n / i};
            
            if (n % i == 0) {
                factors.push(i);
                
                if (i != quotient) {
                    factors.push(quotient);
                }
            }
        }
        
        if (factors.size() >= k) {
            for (auto i{0}; i < k; i++) {
                output = factors.top();
                factors.pop();
            }
        }
        
        return output;
    }
};
