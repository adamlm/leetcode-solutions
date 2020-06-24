class Solution {
public:
    int firstUniqChar(string s) {
        int chars[26] = {0};
        
        for (const auto ch: s) {
            chars[ch - 'a']++;
        }
        
        for (auto i{0}; i < s.length(); i++) {
            if (chars[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};
