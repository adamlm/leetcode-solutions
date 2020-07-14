class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        auto i{0};
        
        for (auto num: nums) {
            if (num != nums[i]) {
                nums[i + 1] = num;
                i++;
            }
        }
        
        return i + 1;
    }
};
