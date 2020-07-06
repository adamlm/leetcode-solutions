class Solution {
public:
    int countSegments(string s) {
        auto count{0};
        auto i{0};
        auto len{s.length()};
        
        while (i < len) {
            while (i < len && s[i] == ' ') {
                i++;
            }
            
            if (i >= len) {
                break;
            }
            
            count++;
            
            while (i < len && s[i] != ' ') {
                i++;
            }
        }
        
        return count;
    }
};
