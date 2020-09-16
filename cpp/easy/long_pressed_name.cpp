class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        auto n{0};
        auto t{0};
        
        while (n < name.size() && t < typed.size()) {
            auto nCount{0};
            auto tCount{0};
            auto start{name[n]};
            
            while (n < name.size() && name[n] == start) {
                nCount++;
                n++;
            }
            
            while (t < typed.size() && typed[t] == start) {
                tCount++;
                t++;
            }
            
            if (nCount > tCount) {
                return false;
            }
        }
        
        return n == name.size() && t == typed.size()? true: false;
    }
};
