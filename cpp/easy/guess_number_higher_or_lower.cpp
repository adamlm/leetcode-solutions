/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        return helper(1, n);
    }
    
    int helper(const int start, const int end) {
        const long median{(static_cast<long>(start) + end) / 2};
        const auto result{guess(median)};
        
        if (result == 0) {
            return median;
        }
        
        return result == 1? helper(median + 1, end): helper(start, median);
    }
};
