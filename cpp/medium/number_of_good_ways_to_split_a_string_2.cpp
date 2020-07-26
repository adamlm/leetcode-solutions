class Solution {
public:
    int numSplits(string s) {
        int p[26] = {0};
        int q[26] = {0};
        
        auto count{0};
        auto pCount{0};
        auto qCount{0};
        
        for (const auto ch: s) {
            q[ch - 'a']++;
            
            if (q[ch - 'a'] == 1) {
                qCount++;
            }
        }
        
        for (auto i{0}; i < s.length() - 1; i++) {
            const auto ch{s[i] - 'a'};
            
            p[ch]++;
            q[ch]--;
            
            if (q[ch] == 0) {
                qCount--;
            }
            
            if (p[ch] == 1) {
                pCount++;
            }

            if (pCount == qCount) {
                count++;
            }
        }
        
        return count;
    }
};
