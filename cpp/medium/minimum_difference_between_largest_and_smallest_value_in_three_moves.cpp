class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) {
            return 0;
        }
        
        const auto len{nums.size()};
        
        sort(nums.begin(), nums.end());
        
        return min({nums[len - 1] - nums[3], nums[len - 4] - nums[0], nums[len - 2] - nums[2], nums[len - 3] - nums[1]});
    }
};
