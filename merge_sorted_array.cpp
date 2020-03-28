class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto p1_i{m - 1};
        auto p2_i{n - 1};
        
        while (p1_i >= 0 && p2_i >= 0) {
            if (nums2[p2_i] > nums1[p1_i]) {
                nums1[p1_i + p2_i + 1] = nums2[p2_i];
                p2_i--;
            } else {
                nums1[p1_i + p2_i + 1] = nums1[p1_i];
                p1_i--;
            }
        }
        
        if (p2_i >= 0) {
            while (p2_i >= 0) {
                nums1[p2_i] = nums2[p2_i];
                p2_i--;
            }
        }
    }
};
