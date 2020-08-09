class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        auto n{0};
        
        for (const auto a: arr) {
            while (n < a - 1 && k > 0) {
                n++;
                k--;
            }
            
            if (k == 0) {
                return n;
            }
            
            n++;
        }
        
        return k > 0? n + k: n;
    }
};
