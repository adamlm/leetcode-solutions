class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> sChars(128, 0);
        vector<int> tChars(128, 0);
        
        for (auto i{0}; i < s.size(); i++) {
            if (sChars[s[i]] != tChars[t[i]]) {
                return false;
            }
            
            sChars[s[i]] = i + 1;
            tChars[t[i]] = i + 1;
        }
        
        return true;
    }
};
