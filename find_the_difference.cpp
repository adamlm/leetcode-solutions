class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> sCounts(26, 0);
        vector<int> tCounts(26, 0);
        
        for (auto i{0}; i < s.length(); i++) {
            sCounts[s[i] - 'a']++;
            tCounts[t[i] - 'a']++;
        }
        
        tCounts[t[t.length() - 1] - 'a']++;
        
        for (auto i{0}; i < 26; i++) {
            if (sCounts[i] != tCounts[i]) {
                return 'a' + i;
            }
        }
        
        return 'a';
    }
};
