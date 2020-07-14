class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int distances[points.size()];
        const auto nPoints{points.size()};
        auto boomerangs{0};
        
        for (auto i{0}; i < nPoints; i++) {
            // Calc all distances between i and j
            for (auto j{0}; j < nPoints; j++) {
                const auto dx{points[i][0] - points[j][0]};
                const auto dy{points[i][1] - points[j][1]};
                
                distances[j] = dx * dx + dy * dy;
            }
            
            // Sort distances (e.g., [1,1,2,2,3,...])
            sort(distances, distances + nPoints);
            auto nEqual{0};
            
            for (auto j{0}; j < nPoints; j++) {
                // If two consecutive points are equal, we found boomerang
                // Else, we are moving on to another list of (possibly) equal points
                if (j > 0 && distances[j] == distances[j - 1]) {
                    nEqual++;
                } else {
                    // Need to add previously found equal points
                    boomerangs += nEqual * (nEqual - 1);  // nP2
                    nEqual = 1;
                }
            }
            
            if (nEqual > 0) {
                boomerangs += nEqual * (nEqual - 1);  // nP2
            }
        }
        
        return boomerangs;
    }
};
