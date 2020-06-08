class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto zerosStart{nums.begin()};
        
        for (auto it{nums.begin()}; it < nums.end(); it++) {
            if (*it != 0) {
                swap(*it, *zerosStart);
                zerosStart++;
            }
        }
    }
};
