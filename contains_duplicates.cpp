class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> values;
        
        for (auto num: nums) {
            if (values.find(num) != values.end()) {
                return true;
            }
            
            values.insert(num);
        }
        
        return false;
    }
};
