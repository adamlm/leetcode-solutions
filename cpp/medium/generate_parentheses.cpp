class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string parens(2 * n, ' ');
        vector<string> ret;
        
        fill(parens.begin(), parens.end() - n, '(');
        fill(parens.end() - n, parens.end(), ')');
        
        do {
            if (is_valid(parens)) {
                ret.push_back(parens);
            }
        } while (next_permutation(parens.begin(), parens.end()));
        
        return ret;
    }
    
private:
    bool is_valid(const string_view& str) {
        stack<char> s;
        
        for (const auto& ch: str) {
            if (ch == '(') {
                s.push(ch);
            } else {
                if (s.empty() || s.top() != '(') {
                    return false;
                } else {
                    s.pop();
                }
            }
        }
        
        return s.empty();
    }
};
