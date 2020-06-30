class Solution {
public:
    int longestPalindrome(string s) {
        auto length{0};
        unordered_map<char, int> chars;
        bool oddUsed{false};
        
        for (const auto ch: s) {
            chars[ch]++;
        }
        
        for (const auto elem: chars) {
            const auto count{elem.second};
            
            if (count % 2 == 0 || !oddUsed) {
                length += count;
                
                if (count % 2 != 0) {
                    oddUsed = true;
                }
            } else {
                length += count - 1;
            }
        }
        
        return length;
    }
};
