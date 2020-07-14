class Solution {
public:
    bool isPalindrome(string s) {
        auto left = s.begin();
        auto right = s.end() - 1;
        
        while (left < right) {
            while (!isalnum(*left) && left < right) {
                left++;
            }
            while (!isalnum(*right) && left < right) {
                right--;
            }
            if (left >= right) {
                break;
            }
            if (tolower(*left) != tolower(*right)) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};
