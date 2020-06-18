class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> output;
        unordered_set<int> numSet;
        unordered_set<int> outSet;
        
        for (const auto num: nums1) {
            numSet.insert(num);
        }
        
        for (const auto num: nums2) {
            if (numSet.find(num) != numSet.end() && outSet.find(num) == outSet.end()) {
                output.push_back(num);
                outSet.insert(num);
            }
        }
        
        return output;
    }
};
