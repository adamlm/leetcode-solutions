class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        auto maxDist{0};
        
        for (const auto ant: left) {
            if (ant > maxDist) {
                maxDist = ant;
            }
        }
        
        for (const auto ant: right) {
            if (n - ant > maxDist) {
                maxDist = n - ant;
            }
        }
        
        return maxDist;
    }
};
