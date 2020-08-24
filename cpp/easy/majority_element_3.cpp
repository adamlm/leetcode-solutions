class Solution {
private:
    int majorityElement(vector<int>& nums, const int low, const int high) {
        if (low == high) {
            return nums[low];
        }
        
        const auto mid{(low + high) / 2};
        const auto left{majorityElement(nums, low, mid)};
        const auto right{majorityElement(nums, mid + 1, high)};
        
        if (left == right) {
            return left;
        }
        
        const auto leftCount{countVal(nums, low, high, left)};
        const auto rightCount{countVal(nums, low, high, right)};
        
        return leftCount > rightCount? left: right;
    }
    
    int countVal(vector<int>& nums, const int low, const int high, const int val) {
        auto count{0};
        
        for (auto i{low}; i <= high; i++) {
            if (nums[i] == val) {
                count++;
            }
        }
        
        return count;
    }
    
public:
    int majorityElement(vector<int>& nums) {
        return majorityElement(nums, 0, nums.size() - 1);
    }
};
