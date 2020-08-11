class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainders(k);
        
        for (auto a: arr) {
            a %= k;
            
            if (a < 0) {
                a += k;
            }
            
            remainders[a]++;
        }
        
        if (remainders[0] % 2 != 0) {
            return false;
        }
        
        for (auto i{1}; i <= k / 2; i++) {
            if (remainders[i] != remainders[k - i]) {
                return false;
            }
        }
        
        return true;
    }
};
