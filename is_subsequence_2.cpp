class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) {
            return true;
        }
        
        auto sIt{s.begin()};
        auto end{s.end()};
        
        for (const auto ch: t) {
            if (ch == *sIt) {
                sIt++;
                
                if (sIt >= end) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
