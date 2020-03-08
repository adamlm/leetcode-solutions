class Solution {
public:
    string convert(string s, int numRows) {
        string output{""};
        auto start{0};
        auto d1{2*(numRows - 1)};
        auto d2 = d1;
        
        if (s.empty())
            return "";
        
        if (s.length() <= numRows || numRows == 1) {
            return s;
        }
        
        while (d2 >= 0) {
            for (auto i{start}; i < s.length(); i += d1) {
                output += s[i];
                if (d2 != d1 && d2 != 0 && i + d2 < s.length()) {
                    output += s[i + d2];
                }
            }
            
            start++;
            d2 -= 2;
        }
        
        return output;
    }
};
