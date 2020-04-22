class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> counts;
        
        for (auto num: nums) {
            if (counts.find(num) != counts.end()) {
                counts[num]++;
            } else {
                counts[num] = 1;
            }
        }
        
        for (auto element: counts) {
            if (element.second == 1) {
                return element.first;
            }
        }
        
        return 0;
    }
};
