class Solution {
public:
    bool isPathCrossing(string path) {
        auto x{0};
        auto y{0};
        
        set<pair<int,int>> locations;
        locations.insert({x,y});
        
        for (const auto s: path) {
            switch(s) {
                case 'N':
                    y++;
                    break;
                case 'S':
                    y--;
                    break;
                case 'E':
                    x++;
                    break;
                case 'W':
                    x--;
                    break;
            }
            
            if (locations.find({x, y}) != locations.end()) {
                return true;
            }
            
            locations.insert({x, y});
        }
        
        return false;
    }
};
