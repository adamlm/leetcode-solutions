class Solution {
public:
    int numSplits(string s) {
        auto count{0};
        map<char, int> p;
        map<char, int> q;
        auto pCount{0};
        auto qCount{0};
        
        for (const auto ch: s) {
            q[ch]++;
            
            if (q[ch] == 1) {
                qCount++;
            }
        }
        
        for (auto i{0}; i < s.length() - 1; i++) {
            p[s[i]]++;
            q[s[i]]--;
            
            if (q[s[i]] == 0) {
                qCount--;
            }
            
            if (p[s[i]] == 1) {
                pCount++;
            }

            if (pCount == qCount) {
                count++;
            }
        }
        
        return count;
    }
};
