class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> counts;
        vector<int> output;
        
        for (const auto n: nums1) {
            if (counts.find(n) == counts.end()) {
                counts[n] = 1;
            } else {
                counts[n]++;
            }
        }
        
        for (const auto n: nums2) {
            if (counts.find(n) != counts.end() && counts[n] > 0) {
                output.push_back(n);
                counts[n]--;
            }
        }
        
        return output;
    }
};
