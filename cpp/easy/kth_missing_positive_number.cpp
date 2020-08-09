class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        auto n{0};
        auto i{0};
        const auto len{arr.size()};
        
        while (k > 0 && i < len) {
            while (n < arr[i] - 1 && k > 0) {
                n++;
                k--;
            }
            
            if (k == 0) {
                return n;
            }
            
            n++;
            i++;
        }
        
        if (k > 0) {
            return n + k;
        }
        
        return n;
    }
};
