class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string output{""};
        auto i{0};
        
        if (strs.size() == 0) {
            return output;
        }
        
        while(1) {
            auto ch{0};
            for (auto it = strs.begin(); it < strs.end(); it++) {
                if (i >= (*it).length()) {
                    return output;
                }

                if (it == strs.begin()) {
                    ch = (*it)[i];
                } else if ((*it)[i] != ch) {
                    return output;
                }
            }

            output.push_back(ch);
            i++;
        }
    }
};
