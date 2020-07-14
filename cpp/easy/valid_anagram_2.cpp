class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        vector<int> lettersS(26);
        vector<int> lettersT(26);
        
        for (auto i{0}; i < s.size(); i++) {
            lettersS[s[i] - 97]++;
            lettersT[t[i] - 97]++;
        }
        
        for (auto i{0}; i < lettersS.size(); i++) {
            if (lettersS[i] != lettersT[i]) {
                return false;
            }
        }
        
        return true;
    }
};
