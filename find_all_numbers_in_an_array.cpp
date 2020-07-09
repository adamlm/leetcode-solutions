class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        vector<int> output;
        
        for (auto i{1}; i <= nums.size(); i++) {
            if (numSet.find(i) == numSet.end()) {
                output.push_back(i);
            }
        }
        
        return output;
    }
};
