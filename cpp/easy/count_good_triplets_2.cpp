class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        auto count{0};
        const auto len{arr.size()};
        
        for (auto i{0}; i < len; i++) {
            for (auto j{i + 1}; j < len; j++) {
                if (abs(arr[i] - arr[j]) <= a) {
                    for (auto k{j + 1}; k < len; k++) {
                        if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                            count++;
                        }
                    }
                }
            }
        }
        
        return count;
    }
};
