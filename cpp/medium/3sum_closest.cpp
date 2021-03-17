class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        auto best_d{numeric_limits<int>::max()};
        auto best_s{0};
        
        sort(begin(nums), end(nums));
        
        for (auto i{begin(nums)}; i < end(nums); ++i) {
            auto front{i + 1};
            auto back{end(nums) - 1};
            
            while (front < back) {
                const auto sum{*i + *front + *back};
                const auto delta{sum - target};

                if (abs(delta) < best_d) {
                    best_d = abs(delta);
                    best_s = sum;
                }

                if (delta == 0) {
                    return best_s;
                } else if (delta < 0) {
                    front++;
                } else {
                    back--;
                }
            }
        }
        
        return best_s;
    }
};
