class Solution {
public:
    int majorityElement(vector<int>& nums) {
        auto count{0};
        auto majority{nums[0]};
        
        for (auto num: nums) {
            if (count == 0) {
                majority = num;
            }
            count += (num == majority) ? 1 : -1;
        }
        
        return majority;
    }
};
