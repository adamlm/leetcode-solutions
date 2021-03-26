class Solution {
private:
    int bin_search(vector<int>& nums, int target) {
        auto left{0};
        auto right{nums.size()};
        
        while (left < right) {
            auto mid = (left + right) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return -1;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto start = bin_search(nums, target);
        
        if (start == -1) {
            return {-1, -1};
        }
        
        auto left{start};
        while (left >= 0 && nums[left] == target) {
            left--;
        }
        
        auto right{start};
        while (right < nums.size() && nums[right] == target) {
            right++;
        }
        
        return {left + 1, right - 1};
    }
};
