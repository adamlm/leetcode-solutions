class Solution {
public:
    string intToRoman(int num) {
        string output;
        const int nums[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        const string syms[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        
        for (auto i{12}; i >= 0; i--) {
            const auto current = nums[i];
            
            while (num >= current) {
                output.append(syms[i]);
                num -= current;
            }
        }        

        return output;
    }
};
