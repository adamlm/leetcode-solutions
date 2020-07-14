class Solution {
public:
    int majorityElement(vector<int>& nums) {
        auto threshold{nums.size() / 2};
        map<int, int> counts;
        
        for (auto num: nums) {
            if (counts.find(num) == counts.end()) {
                counts[num] = 1;
            } else if (counts[num] >= threshold) {
                return num;
            } else {
                counts[num]++;
            }
        }
        
        return nums[0];
    }
};
