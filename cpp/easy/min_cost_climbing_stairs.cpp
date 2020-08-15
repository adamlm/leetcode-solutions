class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        auto sum0{cost[0]};
        auto sum1{cost[1]};
        
        for (auto i{2}; i < cost.size(); i++) {
            const auto minSum = cost[i] + min(sum0, sum1);
            sum0 = sum1;
            sum1 = minSum;
        }
        
        return min(sum0, sum1);
    }
};
