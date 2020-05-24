class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> prevs;
        
        for (auto i{0}; i < nums.size(); i++) {
            if (prevs.size() > k) {
                prevs.erase(nums[i - k - 1]);
            }
            
            if (prevs.find(nums[i]) != prevs.end()) {
                return true;
            }
            
            prevs.insert(nums[i]);
        }
        
        return false;
    }
};
