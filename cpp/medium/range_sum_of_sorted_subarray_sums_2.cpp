class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        auto output{0};
        const auto mod{1000000007};
        
        for (auto i{0}; i < n; i++) {
            auto sum{0};
            
            for (auto j{i}; j < n; j++) {
                sum += nums[j];
                sums.push_back(sum);
            }
        }
        
        sort(sums.begin(), sums.end());
        
        for (auto i{left - 1}; i < right; i++) {
            output = (output + sums[i]) % mod;
        }
        
        return output;
    }
};
