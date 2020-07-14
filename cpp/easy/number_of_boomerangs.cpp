class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        auto boomerangs{0};
        
        for (const auto i: points) {
            unordered_map<int, int> dict(points.size());
            
            for (const auto j: points) {
                const auto dist{pow(i[0] - j[0], 2) + pow(i[1] - j[1], 2)};
                
                dict[dist]++;
            }
            
            for (const auto e: dict) {
                const auto count{e.second};
                
                if (count > 1) {
                    boomerangs += count * (count - 1);
                }
            }
        }
        
        return boomerangs;
    }
};
