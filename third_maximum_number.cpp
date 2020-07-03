class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> maxes;
        auto maxVal{nums[0]};
        auto thirdMin{INT_MIN};
        auto counts{0};
        
        for (const auto n: nums) {
            auto contained{false};
            
            for (const auto m: maxes) {
                if (m == n) {
                    contained = true;
                    break;
                }
            }
            
            if (contained) {
                continue;
            }
            
            if (n > thirdMin || maxes.size() < 3) {
                if (maxes.size() < 3) {
                    maxes.push_back(n);
                } else {
                    for (auto i{0}; i < maxes.size(); i++) {
                        if (maxes[i] == thirdMin) {
                            maxes[i] = n;                        
                            break;
                        }
                    }
                }
                
                thirdMin = INT_MAX;
                maxVal = INT_MIN;
                
                for (const auto m: maxes) {
                    if (m < thirdMin) {
                        thirdMin = m;
                    }
                    
                    if (m > maxVal) {
                        maxVal = m;
                    }
                }
            }
        }
        
        return maxes.size() == 3? thirdMin: maxVal;
    }
};
