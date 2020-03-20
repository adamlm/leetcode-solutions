class Solution {
public:
    int maxArea(vector<int>& height) {
        auto maxArea{0};
        auto start{0};
        
        while (start < height.size()) {
            for (auto end{start}; end < height.size(); end++) {
                auto area = (end - start)*min(height[start], height[end]);
                if (area > maxArea) {
                    maxArea = area;
                }
            }
            start++;
        }
        
        return maxArea;
    }
};
