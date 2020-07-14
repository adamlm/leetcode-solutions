class Solution {
public:
    string getHint(string secret, string guess) {
        auto bulls{0};
        auto cows{0};
        vector<char> sChars;
        unordered_map<char, int> gChars;
        
        for (auto i{0}; i < guess.length(); i++) {
            const auto ch{guess[i]};
            
            if (secret[i] == ch) {
                bulls++;
            } else {
                sChars.push_back(secret[i]);
                
                if (gChars.find(guess[i]) == gChars.end()) {
                    gChars[guess[i]] = 1;
                } else {
                    gChars[guess[i]]++;
                }
            }
        }
        
        for (auto ch: sChars) {
            if (gChars.find(ch) != gChars.end() && gChars[ch] > 0) {
                cows++;
                gChars[ch]--;
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
