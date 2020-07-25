class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        auto empty{0};
        auto count{0};
        
        while (numBottles > 0) {
            count += numBottles;
            empty = numBottles + empty;
            numBottles = empty / numExchange;
            empty %= numExchange;
        }
        
        return count;
    }
};
