class Solution {
public:
    int binaryGap(int N) {
        auto dist{0};
        auto maxDist{INT_MIN};
        auto ones{0};
        
        while (N > 0) {
            if (N & 0x1) {
                if (ones > 0) {
                    maxDist = max(maxDist, dist);
                }
                dist = 0;
                ones++;
            }
            
            dist++;
            N >>= 1;
        }
        
        return ones >= 2? maxDist: 0;
    }
};
