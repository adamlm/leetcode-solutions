class Solution {
public:
    string makeGood(string s) {
        auto bad{false};
        string output;
        const auto len{s.length()};
        
        for (auto i{0}; i < len; i++) {
            if (tolower(s[i]) != tolower(s[i + 1]) || s[i] == s[i + 1]) {
                output.push_back(s[i]);
            } else {
                bad = true;
                i++;
            }
        }
        
        return bad? makeGood(output): output;
    }
};
