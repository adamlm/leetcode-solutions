class Solution {
public:
    int myAtoi(string str) {
        auto isPos{true};
        auto output{0};
        auto readSign{false};
        auto readNum{false};
        
        for (auto const& ch: str) {
            if (ch >= '0' && ch <= '9') {
                if (isPos) {
                    if (output != 0 && (INT_MAX / (-1 * output) < 10)) {
                        return INT_MAX;
                    } else if (INT_MAX + 10 * output <= (ch - 48)) {
                        return INT_MAX;
                    }
                } else {
                    if (output != 0 && (INT_MIN / (-1 * output) > -10)) {
                        return INT_MIN;
                    } else if (INT_MIN - 10 * output >= (-1 * (ch - 48))) {
                        return INT_MIN;
                    }
                }
                output = output * 10 - (ch - 48);
                readNum = true;
            } else if (readNum || readSign) {
                return isPos? -1 * output: output;
            } else if (ch == '-') {
                isPos = false;
                readSign = true;
            } else if (ch == '+') {
                readSign = true;
            } else if (ch != ' ') {
                return isPos? -1 * output: output;
            }
        }
        
        return isPos? -1 * output: output;
    }
};
