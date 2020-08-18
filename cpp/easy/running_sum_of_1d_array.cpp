class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> output{nums[0]};
        
        for (auto i{1}; i < nums.size(); i++) {
            output.push_back(nums[i] + output[i - 1]);
        }
        
        return output;
    }
};
