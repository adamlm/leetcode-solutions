class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) {
            return true;
        }
        
        auto sIt{s.begin()};
        
        for (const auto ch: t) {
            if (ch == *sIt) {
                sIt++;
                
                if (sIt >= s.end()) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
