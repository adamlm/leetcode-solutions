class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) {
            return image;
        }
        
        const auto rows{static_cast<int>(image.size())};
        const auto cols{static_cast<int>(image[0].size())};
        const auto oldColor{image[sr][sc]};
        
        image[sr][sc] = newColor;        
        
        if (sr > 0 && image[sr - 1][sc] == oldColor) {
            floodFill(image, sr - 1, sc, newColor);
        }
        
        if (sr < rows - 1 && image[sr + 1][sc] == oldColor) {
            floodFill(image, sr + 1, sc, newColor);
        }
        
        if (sc > 0 && image[sr][sc - 1] == oldColor) {
            floodFill(image, sr, sc - 1, newColor);
        }
        
        if (sc < cols - 1 && image[sr][sc + 1] == oldColor) {
            floodFill(image, sr, sc + 1, newColor);
        }
        
        return image;        
    }
};
