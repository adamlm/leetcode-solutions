class Solution {
public:
    void reverseString(vector<char>& s) {
        if (!s.empty()) {
            auto left{s.begin()};
            auto right{s.end() - 1};

            while (left < right) {
                swap(*left, *right);
                left++;
                right--;
            }
        }
    }
};
