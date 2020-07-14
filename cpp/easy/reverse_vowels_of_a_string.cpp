class Solution {
public:
    string reverseVowels(string s) {
        if (s.empty()) {
            return "";
        }
        
        auto output{s};
        auto left{0};
        auto right{s.length() - 1};
        
        while (left < right) {
            while (left < output.size() && !isVowel(output[left])) {
                left++;
            }
            
            while (right > 0 && !isVowel(output[right])) {
                right--;
            }
            
            if (left < right) {
                swap(output[left], output[right]);
                left++;
                right--;
            } else {
                break;
            }
        }
        
        return output;
    }
    
    bool isVowel(const char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
            || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
};
