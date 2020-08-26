class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> sS;
        stack<char> sT;
        
        for (const auto c: S) {
            if(c != '#') {
                sS.push(c);
            } else if (!sS.empty()) {
                sS.pop();
            }
        }
        
        for (const auto c: T) {
            if(c != '#') {
                sT.push(c);
            } else if (!sT.empty()) {
                sT.pop();
            }
        }
        
        while (!sS.empty() && !sT.empty()) {
            if (sS.top() != sT.top()) {
                return false;
            }
            
            sS.pop();
            sT.pop();
        }
        
        return sS.empty() && sT.empty();
    }
};
