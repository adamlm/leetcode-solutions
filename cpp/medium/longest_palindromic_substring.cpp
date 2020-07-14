class Solution {
public:
    string longestPalindrome(string s) {
        auto start{0};
        auto end{0};
        auto maxLen{0};
        
        if (s.empty()) {
            return "";
        }
        
        for (auto i{0}; i < s.length(); i++) {
            auto lenOdd = expand(s, i, i);
            auto lenEven = expand(s, i, i + 1);
            auto len = max(lenOdd, lenEven);
            
            if (len > maxLen) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
                maxLen = len;
            }
        }
        
        return s.substr(start, maxLen);
    }
private:
    int expand(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        
        return right - left - 1;
    }
};
