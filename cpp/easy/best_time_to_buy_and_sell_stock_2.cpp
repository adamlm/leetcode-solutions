class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        auto buy{prices[0]};
        auto profit{0};
        
        for (const auto price: prices) {
            buy = min(buy, price);
            profit = max(profit, price - buy);
        }
        
        return profit;
    }
};
