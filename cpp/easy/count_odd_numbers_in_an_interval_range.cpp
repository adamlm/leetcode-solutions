class Solution {
public:
    int countOdds(int low, int high) {
        auto count{(high - low + 1) / 2};
        
        return low % 2 != 0 && high % 2 != 0? count + 1: count;
    }
};
