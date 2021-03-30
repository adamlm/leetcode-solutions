class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        
        for (auto i{0}; i <= num; ++i) {
            auto count{0};
            
            for (auto tmp{i}; tmp > 0; tmp >>= 1) {
                count += tmp & 0x1;
            }
            
            ret.push_back(count);
        }
        
        return ret;
    }
};
