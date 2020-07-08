class Solution {
public:
    int compress(vector<char>& chars) {
        auto prev{chars[0]};
        auto count{0};
        auto pos{0};
        
        for (auto it{chars.begin()}; it <= chars.end(); it++) {
            if (it == chars.end() || *it != prev) {
                chars[pos] = prev;
                pos++;
                
                if (count <= 1) {
                    count = 1;
                    if (it != chars.end()) {
                        prev = *it;
                    }
                    continue;
                }
                
                vector<int> digits;
                while (count > 0) {
                    const auto val{count % 10};
                    count /= 10;
                    digits.push_back(val);
                }
                reverse(digits.begin(), digits.end());
                
                for (const auto digit: digits) {
                    chars[pos] = digit + '0';
                    pos++;
                }
            }
            
            count++;
            if (it != chars.end()) {
                prev = *it;
            }
        }
        
        return pos; 
    }
};
