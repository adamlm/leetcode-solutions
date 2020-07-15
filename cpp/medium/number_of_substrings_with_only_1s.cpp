class Solution {
public:
    int numSub(string s) {
        auto output{0};
        auto count{0};
        auto mod{1000000007};
        
        for (const auto ch: s) {
            count = ch == '1'? count + 1: 0;
            output = (output + count) % mod;
        }
        
        return output;
    }
};
