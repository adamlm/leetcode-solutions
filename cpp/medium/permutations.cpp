class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;

        helper(nums, 0, ret);
        
        return ret;
    }
      
    void helper(vector<int>& nums, int start, vector<vector<int>>& ret) {
        if (start >= nums.size()) {
            ret.push_back(nums);
            return;
        }
        
        for (auto i{start}; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            helper(nums, start + 1, ret);
            swap(nums[start], nums[i]);
        }
    }
};
