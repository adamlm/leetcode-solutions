class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int> sums({{0, 0}});
        auto sum{0};
        auto count{0};
        
        for (const auto num: nums) {
            sum += num;
            
            if (sums.find(sum - target) != sums.end()) {
                count = max(count, sums[sum - target] + 1);
            }
            
            sums[sum] = count;
        }
        
        return count;
    }
};
