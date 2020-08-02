class Solution {
public:
    string arrangeWords(string text) {
        text[0] += 32;
        
        string output;
        auto iss = istringstream(text);
        auto str = string{};
        map<int, string> words;
        
        while (iss >> str) {
            words[str.length()] += " " + str;
        }
        
        auto smallest{words.begin()->second};
        auto len{smallest.length()};
        words.begin()->second = smallest.substr(1, len - 1);
        
        for (const auto [k, v]: words) {
            output += v;
        }
        
        output[0] -= 32;
        
        return output;
    }
};
