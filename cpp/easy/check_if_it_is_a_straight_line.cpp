class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates[0][0] == coordinates[1][0]) {
            float x = coordinates[0][0];
            
            for (auto i{0}; i < coordinates.size(); i++) {
                if (abs(coordinates[i][0] - x) > 0.0001) {
                    return false;
                }
            }

            return true;
        }
        
        float m{(coordinates[1][1] - coordinates[0][1]) / (float)(coordinates[1][0] - coordinates[0][0])};
        float b{coordinates[0][1] - m * coordinates[0][0]};
        
        for (auto i{0}; i < coordinates.size(); i++) {
            if (abs(coordinates[i][1] - (m * coordinates[i][0] + b)) > 0.0001) {
                return false;
            }
        }
        
        return true;
    }
};
