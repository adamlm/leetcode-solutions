class Solution {
public:
    int search(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size());
    }
    
    int helper(vector<int>& nums, int target, int left, int right) {
        if (left == right) {
            return -1;
        }
        
        auto mid{(left + right) / 2};
        if (nums[mid] == target) {
            return mid;
        }
        
        if (nums[mid] > target) {
            return helper(nums, target, left, mid);
        }
        
        return helper(nums, target, mid + 1, right);
    }
};
