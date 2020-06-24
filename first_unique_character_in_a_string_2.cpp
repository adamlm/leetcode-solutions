class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> chars;
        
        for (const auto ch: s) {
            chars[ch]++;
        }
        
        for (auto i{0}; i < s.length(); i++) {
            if (chars[s[i]] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};
