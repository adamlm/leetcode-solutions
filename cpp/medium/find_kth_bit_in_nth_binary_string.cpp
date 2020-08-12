class Solution {
public:
    char findKthBit(int n, int k) {
        vector<int> list{0};
        
        for (auto i{0}; i < n - 1; i++) {
            list.push_back(1);
            
            const auto len{static_cast<int>(list.size())};
            for (auto j{len - 2}; j >= 0; j--) {
                list.push_back(!(list[j]));
            }
        }
        
        if (k > list.size()) {
            return !(list[list.size() - k]) + '0';
        }
        
        return list[k - 1] + '0';
    }
};
