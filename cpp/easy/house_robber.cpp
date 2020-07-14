class Solution {
public:
    int rob(vector<int>& nums) {
        auto oneBack{0};
        auto twoBack{0};
        
        for (auto num: nums) {
            auto tmp{oneBack};
            oneBack = max(oneBack, twoBack + num);
            twoBack = tmp;
        }
            
        return oneBack;
    }
};
