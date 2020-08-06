class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        constexpr auto mod{1000000007};
        
        const auto n{static_cast<int>(arr.size())};
        vector<int> zeros(n);
        vector<int> ones(n);
        auto sum{0};
        
        if (arr[n - 1] % 2 == 1) {
            ones[n - 1] = 1;
        } else {
            zeros[n - 1] = 1;
        }
        
        for (auto i{n - 2}; i >= 0; i--) {
            if (arr[i] % 2 == 1) {
                ones[i] = (1 + zeros[i + 1]) % mod;
                zeros[i] = ones[i + 1];
            } else {
                zeros[i] = (1 + zeros[i + 1]) % mod;
                ones[i] = ones[i + 1];
            }
        }
        
        for (const auto one: ones) {
            sum = (sum + one) % mod;
        }
        
        return sum;
    }
};
