class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string output(s);
        
        for (auto i{0}; i < indices.size(); i++) {
            output[indices[i]] = s[i];
        }
        
        return output;
    }
};
