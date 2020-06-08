class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto zeros{0};
        
        for (auto it{nums.begin()}; it < nums.end(); it++) {
            if (*it == 0) {
                nums.erase(it);
                zeros++;
                it--;
            }
        }
        
        for (auto i{0}; i < zeros; i++) {
            nums.push_back(0);
        }
    }
};
