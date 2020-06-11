class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.empty()) {
            return false;
        }
        
        auto iss{istringstream{str}};
        auto token{string{}};
        
        map<string, char> words;
        unordered_set<char> letters;
        auto valChar{'a'};
        auto i{0};
        
        while (iss >> token) {
            if (words.find(token) == words.end()) {
                if (letters.find(pattern[i]) != letters.end()) {
                    return false;
                }
                words[token] = pattern[i];
                letters.insert(pattern[i]);
            }
            
            if (words[token] != pattern[i++]) {
                return false;
            }
        }
        
        return i < pattern.size()? false: true;
    }
};

