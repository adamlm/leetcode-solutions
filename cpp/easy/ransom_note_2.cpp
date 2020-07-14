class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int noteChars[26] = {0};
        int magChars[26] = {0};
        
        for (const auto ch: ransomNote) {
            noteChars[ch - 'a']++;
        }
        
        for (const auto ch: magazine) {
            magChars[ch - 'a']++;
        }
        
        for (auto i{0}; i < 26; i++) {
            if (noteChars[i] > magChars[i]) {
                return false;
            }
        }
        
        return true;
    }
};
