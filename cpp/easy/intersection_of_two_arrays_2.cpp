class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> output;
        unordered_set<int> numSet{nums1.begin(), nums1.end()};
        
        for (const auto num: nums2) {
            if (numSet.count(num) == 1) {
                output.push_back(num);
                numSet.erase(num);
            }
        }
        
        return output;
    }
};
