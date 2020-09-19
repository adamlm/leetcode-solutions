class Solution {
public:
    string removeOuterParentheses(string S) {
        string output;
        stack<int> s;
        auto opened{0};
        auto closed{0};
        
        for (auto ch: S) {
            s.push(ch);
            if (ch == '(') {
                opened++;
            } else {
                closed++;
            }
            
            if (ch == ')' && opened == closed) {
                string tmp;
                s.pop();
                while (s.size() > 1) {
                    tmp.insert(0, 1, s.top());
                    s.pop();
                }
                
                s.pop();
                output += tmp;
                opened = 0;
                closed = 0;
            }
        }
        
        return output;
    }
};
