class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        auto count{0};
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        auto pS{s.begin()};
        auto pG{g.begin()};
        
        while (pG < g.end() && pS < s.end()) {
            if (*pS >= *pG) {
                count++;
                pS++;
                pG++;
            } else {
                pS++;
            }
        }
        
        return count;
    }
};
