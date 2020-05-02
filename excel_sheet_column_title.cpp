class Solution {
public:
    string convertToTitle(int n) {
        string output; 
        
        while (n != 0) {
            auto remainder = n % 26;
            
            if (remainder == 0) {
                output.push_back('Z');
                n--;
            } else {
                output.push_back(remainder + 64);
            }
            
            if (n == 26) {
                break;
            }
            
            n /= 26;
        }
        
        reverse(output.begin(), output.end());
    
        return output;
    }
};
