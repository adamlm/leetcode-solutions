class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<char> substr;
        map<char, int> counts;
        auto length{0};
        
        for (auto const& ch: s) {
            if (counts.find(ch) == counts.end()) {
                counts.insert({ch, 1});
                substr.push(ch);
            } else {
                while (counts.find(ch) != counts.end()) {
                    counts.erase(substr.front());
                    substr.pop();
                }
                counts.insert({ch, 1});
                substr.push(ch);
            }
            
            if (substr.size() > length) {
                length = substr.size();
            }
        }
        
        return length;
    }
};
