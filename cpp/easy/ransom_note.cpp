class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> noteChars;
        unordered_map<char, int> magChars;
        
        for (const auto ch: ransomNote) {
            if (noteChars.find(ch) == noteChars.end()) {
                noteChars[ch] = 1;
            } else {
                noteChars[ch]++;
            }
        }
        
        for (const auto ch: magazine) {
            if (magChars.find(ch) == magChars.end()) {
                magChars[ch] = 1;
            } else {
                magChars[ch]++;
            }
        }
        
        for (auto entry: noteChars) {
            if (magChars.find(entry.first) == magChars.end() 
                || magChars[entry.first] < entry.second) {
                return false;
            }
        }
        
        return true;
    }
};
