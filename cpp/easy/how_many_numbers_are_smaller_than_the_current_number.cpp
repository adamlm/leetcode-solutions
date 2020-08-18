class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int> counts;
        vector<int> output(nums.size(), 0);
        
        for (const auto num: nums) {
            counts[num]++;
        }
        
        for (auto i{0}; i < nums.size(); i++) {
            const auto stop{counts.find(nums[i])};
            auto sum{0};
            
            for (auto e{counts.begin()}; e != stop; e++) {
                sum += e->second;
            }
            
            output[i] = sum;
        }
        
        return output;
    }
};
