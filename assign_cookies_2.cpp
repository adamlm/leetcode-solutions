class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        auto count{0};
        auto iS{0};
        auto iG{0};
        auto gSize{g.size()};
        auto sSize{s.size()};
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        while (iG < gSize && iS < sSize) {
            if (s[iS] >= g[iG]) {
                count++;
                iS++;
                iG++;
            } else {
                iS++;
            }
        }
        
        return count;
    }
};
