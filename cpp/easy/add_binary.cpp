class Solution {
public:
    string addBinary(string a, string b) {
        string output;
        auto carry{0};
        
        for (auto i{0}; i < max(a.length(), b.length()); i++) {
            auto sum{carry};
            
            if (i >= a.length()) {
                sum += (*(b.end() - 1 - i) - '0');
            } else if (i >= b.length()) {
                sum += (*(a.end() - 1 - i) - '0');
            } else {
                sum += (*(a.end() - 1 - i) - '0') + (*(b.end() - 1 - i) - '0');
            }
            carry = sum / 2;
            sum %= 2;
            output.insert(output.begin(), sum + '0');
        }
        
        if (carry) {
            output.insert(output.begin(), carry + '0');
        }
        
        return output;
    }
};
