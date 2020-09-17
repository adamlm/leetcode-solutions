class Solution {
public:
    string defangIPaddr(string address) {
        string output;
        
        for (auto ch: address) {
            if (ch == '.') {
                output += "[.]";
            } else {
                output += ch;
            }
        }
        
        return output;
    }
};
