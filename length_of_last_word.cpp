class Solution {
public:
    int lengthOfLastWord(string s) {
        auto ch{s.end() - 1};
        auto length{0};
        
        while (ch >= s.begin() && *ch == ' ') {
            ch--;
        }
        
        while (ch >= s.begin() && *ch != ' ') {
            length++;
            ch--;
        }
        
        return length;
    }
};
