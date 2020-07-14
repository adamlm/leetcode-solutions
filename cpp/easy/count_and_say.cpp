class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        
        string output;
        int count{0};
        char prevChr{0};
        
        for (auto chr: countAndSay(n - 1)) {
            if (chr == prevChr || count == 0) {
                count++;
            } else {
                output += (count + '0');
                output += (prevChr);
                count = 1;
            }
            prevChr = chr;
        }
        
        output += (count + '0');
        output += (prevChr);
        
        return output;
    }
};
