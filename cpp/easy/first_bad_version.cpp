// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return helper(0, n);
    }
    
    int helper(const long start, const long end) {
        auto mid{(start + end) / 2};
        
        if (isBadVersion(mid)) {
            return !isBadVersion(mid - 1)? mid : helper(0, mid);
        }
        
        return isBadVersion(mid + 1)? mid + 1: helper(mid + 1, end);
    }
};
