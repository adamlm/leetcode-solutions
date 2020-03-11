class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto length{nums.size()};
        
        for (auto i{0}; i < length;) {
            if (nums.at(i) == val) {
                swap(nums.at(i), nums.at(length - 1));
                length--;
                i = 0;
            } else {
                i++;
            }
        }
        
        return length;
    }
};
