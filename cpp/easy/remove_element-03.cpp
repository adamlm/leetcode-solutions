class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto length{nums.size()};
        auto cont{true};
        auto start{0};
        
        while (cont) {
            cont = false;
            for (auto i{start}; i < length; i++) {
                if (nums.at(i) == val) {
                    if (nums.at(length - 1) == val) {
                        cont = true;
                        if (i < start) {
                            start = i;
                        }
                    }
                    swap(nums.at(i), nums.at(length - 1));
                    length--;
                }
            }
        }
        
        return length;
    }
};
