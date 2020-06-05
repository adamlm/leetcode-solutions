class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto max{(nums.size()) * (nums.size() + 1) / 2};
        auto sum{0};
        
        for (auto num: nums) {
            sum += num;
        }
        
        return max - sum;
    }
};
