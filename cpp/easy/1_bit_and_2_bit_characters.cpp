class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for (auto i{0}; i < bits.size(); i++) {
            if (i >= bits.size() - 2) {
                return bits[i] == 0;
            }
            
            if (bits[i] == 1) {
                i++;
            }
        }
        
        return bits[0] == 0? true: false;
    }
};
