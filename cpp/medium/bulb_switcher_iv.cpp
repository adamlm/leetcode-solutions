class Solution {
public:
    int minFlips(string target) {
        auto flip{'0'};
        auto count{0};
        
        for (const auto ch: target) {
            if (ch != flip) {
                count++;
                flip = flip == '0'? '1': '0';
            }
        }
        
        return count;
    }
};
