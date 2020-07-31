class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (m * k > bloomDay.size()) {
            return -1;
        }
        
        auto left{1};
        auto right{1e9};
        
        while (left < right) {
            const auto mid{(left + right) / 2};
            auto flowers{0};
            auto bouquets{0};
            
            for (const auto time: bloomDay) {
                if (time > mid) {
                    flowers = 0;
                } else if (++flowers >= k) {
                    bouquets++;
                    flowers = 0;
                }
            }
            
            if (bouquets >= m) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
