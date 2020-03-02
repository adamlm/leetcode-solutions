class Solution {
public:
    bool isValid(string s) {
        stack<char> chStack;
        
        if (s.length() == 0) {
            return true;
        }
        
        for (auto const& ch: s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                chStack.push(ch);
            } else if (chStack.empty()) {
                return false;
            } else {
                switch(ch) {
                    case ')':
                        if (chStack.top() == '(') {
                            chStack.pop();
                        } else {
                            return false;
                        }
                        break;
                    case ']':
                        if (chStack.top() == '[') {
                            chStack.pop();
                        } else {
                            return false;
                        }
                        break;
                    case '}':
                        if (chStack.top() == '{') {
                            chStack.pop();
                        } else {
                            return false;
                        }
                        break;
                }
            }
        }
        
        if (chStack.empty()) {
            return true;    
        }
        
        return false;
    }
};
