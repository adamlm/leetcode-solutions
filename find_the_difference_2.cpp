class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> sCounts;
        unordered_map<char, int> tCounts;
        
        for (auto i{0}; i < s.length(); i++) {
            sCounts[s[i]]++;
            tCounts[t[i]]++;
        }
        
        tCounts[t[t.length() - 1]]++;
        
        if (sCounts.size() > tCounts.size()) {
            for (const auto e: sCounts) {
                if (e.second != tCounts[e.first]) {
                    return e.first;
                }
            }
        } else {
            for (const auto e: tCounts) {
                if (e.second != sCounts[e.first]) {
                    return e.first;
                }
            }
        }
        
        
        return 'a';
    }
};
