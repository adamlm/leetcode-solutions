class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> output;
        unsigned int bits{0};
        
        while (true) {
            auto sum{0};
            
            for (auto i{0}; i < 10; i++) {
                sum += (bits >> i) & 0x1;
            }
            
            const auto hours{bits >> 6};
            const auto mins{bits & 0x3f};
            
            if (sum == num && hours < 12 && mins < 60) {
                if (mins < 10) {
                    output.emplace_back(to_string(hours) + ":0" + to_string(mins));
                } else {
                    output.emplace_back(to_string(hours) + ":" + to_string(mins));
                }
                
            }
            
            if (hours == 11 && mins == 59) {
                break;
            }
            
            bits++;
        }
        
        return output;
    }
};
