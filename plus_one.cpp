class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto carry{1};
        
        for (auto digit{digits.end() - 1}; digit >= digits.begin(); digit--) {
            auto sum{*digit + carry};
            *digit = sum % 10;
            carry = sum / 10;
        }
        
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
    }
};
