class Solution {
public:
    string addStrings(string num1, string num2) {
        auto carry{0};
        auto sum{0};
        string output;
        
        auto pNum1{num1.end() - 1};
        auto pNum2{num2.end() - 1};
        
        while (pNum1 >= num1.begin() || pNum2 >= num2.begin()) {
            sum = carry;
            if (pNum1 >= num1.begin()) {
                sum += *pNum1 - '0';
                pNum1--;
            }
            
            if (pNum2 >= num2.begin()) {
                sum += *pNum2 - '0';
                pNum2--;
            }
            
            carry = sum / 10;
            sum %= 10;
            
            output.push_back(sum + '0');
        }
        
        if (carry > 0) {
            output.push_back(carry + '0');
        }
        
        reverse(output.begin(), output.end());
        
        return output;
    }
};
