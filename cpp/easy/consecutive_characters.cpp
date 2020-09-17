class Solution {
public:
    int maxPower(string s) {
        auto prev{s[0]};
        auto size{0};
        auto output{1};
        
        for (auto ch: s) {
            if (ch == prev) {
                size++;
            } else {
                output = max(output, size);
                size = 1;
            }
            
            prev = ch;
        }
        
        return max(output, size);
    }
};
