class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<string>> lookup{
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}},
        };
        vector<string> letters;
        
        for (auto digit{crbegin(digits)}; digit != crend(digits); ++digit) {
            if (digit == crbegin(digits)) {
                letters = cart(lookup[*digit], {});
            } else {
                letters = cart(lookup[*digit], letters);
            }
        }
        
        return letters;
    }

private:
    vector<string> cart(vector<string> lhs, vector<string> rhs) {
        if (lhs.empty()) {
            return rhs;
        } else if (rhs.empty()) {
            return lhs;
        }
        
        vector<string> ret;
        
        for(const auto& l: lhs) {
            for (const auto& r: rhs) {
                ret.push_back(l + r);
            }
        }
        
        return ret;
    }
};
