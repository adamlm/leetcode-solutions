class Solution {
public:
    string toHex(int num) {
        string output;
        
        for (auto i{0}; i < 8; i++) {
            auto val{num & 0xf};
            
            val = val > 9? (val - 10) + 'a': val + '0';
            output.push_back(static_cast<char>(val));
            
            num >>= 4;
            if (num == 0) {
                break;
            }
        }
        
        reverse(output.begin(), output.end());
        
        return output;
    }
};
