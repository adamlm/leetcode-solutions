class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums(n, start);
        auto exor{0};
        
        for (auto i{0}; i < n; i++) {
            nums[i] += 2 * i;
        }
        
        for (const auto n: nums) {
            exor ^= n;
        }
        
        return exor;
    }
};
