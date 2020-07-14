class Solution {
public:
    string intToRoman(int num) {
        string output;
        
        if (num >= 1000) {
            switch (num / 1000) {
                case 3:
                    output.append("M");
                case 2:
                    output.append("M");
                case 1:
                    output.append("M");
            }
            
            num %= 1000;
        }
        
        if (num >= 100) {
            switch(num / 100) {
                case 4:
                    output.append("CD");
                    break;
                case 5:
                    output.append("D");
                    break;
                case 9:
                    output.append("CM");
                    break;
                default:
                    if (num > 500) {
                        output.append("D");
                        num -= 500;
                    }
                    
                    while (num >= 100) {
                        output.append("C");
                        num -= 100;
                    }
            }
            
            num %= 100;
        }

        if (num >= 10) {
            switch(num / 10) {
                case 4:
                    output.append("XL");
                    break;
                case 5:
                    output.append("L");
                    break;
                case 9:
                    output.append("XC");
                    break;
                default:
                    if (num > 50) {
                        output.append("L");
                        num -= 50;
                    }
                    while (num >= 10) {
                        output.append("X");
                        num -= 10;
                    }
            }
            
            num %= 10;
        }

        switch(num) {
            case 4:
                output.append("IV");
                break;
            case 5:
                output.append("V");
                break;
            case 9:
                output.append("IX");
                break;
            default:
                if (num > 5) {
                    output.append("V");
                    num -= 5;
                }
                
                while (num > 0) {
                    output.append("I");
                    num--;
                }
        }

        return output;
    }
};
