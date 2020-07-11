class Solution {
public:
    int minMoves(vector<int>& nums) {
        auto sum{0};
        auto min{INT_MAX};
        
        for (const auto n: nums) {
            sum += n;
            
            if (n < min) {
                min = n;
            }
        }
        
        return sum - min * nums.size();
    }
};

