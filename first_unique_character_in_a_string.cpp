class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int, int>> chars(26, pair(0,0));
        auto first{-1};
        
        for (auto i{0}; i < s.length(); i++) {
            chars[s[i] - 'a'].first = i;
            chars[s[i] - 'a'].second++;
        }
        
        for (auto p: chars) {
            if (p.second == 1) {
                if (first == -1 || p.first < first) {
                    first = p.first;
                }
            }
        }
        
        return first;
    }
};
