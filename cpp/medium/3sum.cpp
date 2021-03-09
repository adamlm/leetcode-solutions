class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        sort(begin(nums), end(nums));
        
        for (auto i{nums.begin()}; i < nums.end(); ++i) {
            auto front{i + 1};
            auto back = nums.end() - 1;
            const auto target{-*i};
            
            while (front < back) {
                const auto sum{*front + *back};
                
                if (sum < target) {
                    front++;
                } else if (sum > target) {
                    back--;
                } else {
                    const auto f{*front};
                    const auto b{*back};
                    res.push_back({*i, f, b});
                    
                    while (front < back && *front == f) {
                        front++;
                    }
                    
                    while (front < back && *back == b) {
                        back--;
                    }
                }
            }
            
            while (next(i, 1) < nums.end() && *next(i, 1) == *i) {
                i++;
            }
        }
        
        return res;
    }
};
