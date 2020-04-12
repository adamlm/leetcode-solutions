class Solution {
public:
    bool isPalindrome(string s) {
        auto left = s.begin();
        auto right = s.end() - 1;
        
        while (left < right) {
            while ((tolower(*left) < '0' || tolower(*left) > 'z' 
                   || (tolower(*left) < 'a' && tolower(*left) > '9'))
                   && left < right) {
                left++;
            }
            while ((tolower(*right) < '0' || tolower(*right) > 'z' 
                   || (tolower(*right) < 'a' && tolower(*right) > '9'))
                   && left < right) {
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
