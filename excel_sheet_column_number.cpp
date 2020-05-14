class Solution {
public:
    int titleToNumber(string s) {
        auto num{0};
        
        for (auto ch: s) {
            auto col = (int)ch - 64;
            num = num * 26 + col;
        }
        
        return num;
    }
};
