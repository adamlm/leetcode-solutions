class Solution {
public:
    int kthFactor(int n, int k) {
        if (k == 1) {
            return 1;
        }
    
        vector<int> factors;
        const auto root{sqrt(n)};
        
        for (auto i{1}; i <= root; i++) {
            const auto quotient{n / i};
            
            if (n % i == 0) {
                factors.push_back(i);
                
                if (i != quotient) {
                    factors.push_back(quotient);
                }
            }
        }
        
        sort(factors.begin(), factors.end());
        
        return factors.size() >= k? factors[k - 1]: -1;
    }
};
