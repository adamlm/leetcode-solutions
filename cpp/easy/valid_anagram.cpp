class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> letters;
        
        for (auto ch: s) {
            if (letters.find(ch) == letters.end()) {
                letters[ch] = 1;
            } else {
                letters[ch]++;
            }
        }
        
        for (auto ch: t) {
            if (letters.find(ch) == letters.end()) {
                return false;
            }
            
            letters[ch]--;
            
            if (letters[ch] == 0) {
                letters.erase(ch);
            }
        }
        
        return letters.empty()? true: false;
    }
};
