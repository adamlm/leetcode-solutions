class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2 || k <= 0 || t < 0) {
            return false;
        }
        
        multiset<long> s;
        const auto n{static_cast<int>(nums.size())};
        
        for (auto i{0}; i < n; i++) {
            auto upper{s.upper_bound(static_cast<long>(nums[i]) + t)};
            auto lower{s.lower_bound(static_cast<long>(nums[i]) - t)};
            
            if (upper != lower) {
                return true;
            }
            
            s.insert(nums[i]);
            if (s.size() > k) {
                s.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};
