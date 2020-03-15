class Solution {
public:
    int strStr(string haystack, string needle) {
        auto found{true};
        
        if (needle.empty()) {
            return 0;
        }
        
        if (haystack.empty()) {
            return -1;
        }

        for (auto i{0}; i <= (int)haystack.length() - (int)needle.length(); i++) {
            found = true;
            
            for (auto j{0}; j < needle.length(); j++) {
                if (haystack[i + j] != needle[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return i;
            }
        }
        
        return -1;
    }
};
