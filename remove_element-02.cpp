class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto length{nums.size()};
        auto cont{true};
        
        while (cont) {
            cont = false;
            for (auto i{0}; i < length; i++) {
                if (nums.at(i) == val) {
                    if (nums.at(length - 1) == val) {
                        cont = true;
                    }
                    swap(nums.at(i), nums.at(length - 1));
                    length--;
                }
            }
        }
        
        return length;
    }
};
