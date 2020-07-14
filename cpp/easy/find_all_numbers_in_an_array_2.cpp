class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> output(nums.size(), 1);
        auto p{0};
        
        for (const auto n: nums) {
            output[n - 1] = 0;
        }
        
        for (auto i{1}; i <= nums.size(); i++) {
            if (output[i - 1] == 1) {
                output[p] = i;
                p++;
            }
        }
        
        output.resize(p);
        
        return output;
    }
};
