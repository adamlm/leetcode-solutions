class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n, true);
        auto count{0};
        
        for (auto i{2}; i * i < n; i++) {
            if (primes[i] == true) {
                for (auto j{i * i}; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }
        
        for (auto i{2}; i < n; i++) {
            if (primes[i] == true) {
                count++;
            }
        }
        
        return count;
    }
};
