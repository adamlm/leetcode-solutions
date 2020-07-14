class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int> sChars;
        map<char, int> tChars;
        
        for (auto i{0}; i < s.size(); i++) {
            if (sChars.find(s[i]) == sChars.end()) {
                sChars[s[i]] = sChars.size();
            }
            
            if (tChars.find(t[i]) == tChars.end()) {
                tChars[t[i]] = tChars.size();
            }
            
            if (sChars[s[i]] != tChars[t[i]]) {
                return false;
            }
        }
        
        return true;
    }
};
