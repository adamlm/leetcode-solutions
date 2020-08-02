class Solution {
public:
    string arrangeWords(string text) {
        text[0] += 32;
        
        string output;
        auto iss = istringstream(text);
        auto str = string{};
        map<int, string> words;
        
        while (iss >> str) {
            const auto len{str.length()};
            
            if (words.find(len) != words.end()) {
                words[len] += " " + str;
            } else {
                words[len] = " " + str;
            }
        }
        
        for (const auto [k, v]: words) {
            output += v;
        }
        
        output[1] -= 32;
        
        return output.substr(1, output.length() - 1);
    }
};
