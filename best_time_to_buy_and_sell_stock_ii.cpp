class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto profit{0};
        
        for (auto price{prices.begin() + 1}; price < prices.end(); price++) {
            auto diff{*price - *(price - 1)};
            profit += diff > 0? diff: 0;
        }
        
        return profit;
    }
};
