class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sumQueue;
        auto output{0};
        const auto mod{1000000007};
    
        for (auto i{0}; i < n; i++) {
            sumQueue.push({nums[i], i + 1});
        }
        
        for (auto i{1}; i <= right; i++) {
            auto smallest = sumQueue.top();
            sumQueue.pop();
            
            if (i >= left) {
                output = (output + smallest.first) % mod;
            }
            
            if (smallest.second < n) {
                smallest.first += nums[smallest.second++];
                sumQueue.push(smallest);
            }
        }
        
        return output;
    }
};
