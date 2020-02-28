class Solution {
public:
    int romanToInt(string s) {
        auto num{0};
        auto prv_ch{0};
        
        for (auto ch : s) {
            switch(ch) {
                case 'I':
                    num++;
                    break;
                case 'V':
                    num += 5;
                    if (prv_ch == 'I')
                        num -= 2*1;
                    break;
                case 'X':
                    num += 10;
                    if (prv_ch == 'I')
                        num -= 2*1;
                    break;
                case 'L':
                    num += 50;
                    if (prv_ch == 'X')
                        num -= 2*10;
                    break;
                case 'C':
                    num += 100;
                    if (prv_ch == 'X')
                        num -= 2*10;
                    break;
                case 'D':
                    num += 500;
                    if (prv_ch == 'C')
                        num -= 2*100;
                    break;
                case 'M':
                    num += 1000;
                    if (prv_ch == 'C')
                        num -= 2*100;
                    break;
                default:
                    break;
            };
            
            prv_ch = ch;
        }
        
        return num;
    }
};
