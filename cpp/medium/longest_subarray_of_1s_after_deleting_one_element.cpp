class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        auto left{0};
        auto right{0};
        auto max{0};
        
        for (const auto n: nums) {
            if (n == 0) {
                if (left + right > max) {
                    max = left + right;
                }
                
                left = right;
                right = 0;
            } else {
                right++;
            }
        }
        
        if (left + right > max) {
            max = left + right;
        }
        
        return right == nums.size()? max - 1: max;
    }
};
