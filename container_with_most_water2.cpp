class Solution {
public:
    int maxArea(vector<int>& height) {
        auto maxArea{0};
        auto start{height.begin()};
        auto end{height.end() - 1};
        
        while (start != end) {
            auto area = (end - start)*min(*start, *end);
            if (area > maxArea) {
                maxArea = area;
            }
            if (*start < *end) {
                start++;
            } else {
                end--;
            }
        }
        
        return maxArea;
    }
};
