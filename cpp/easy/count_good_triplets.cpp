class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        auto count{0};
        const auto len{arr.size()};
        
        for (auto i{0}; i < len; i++) {
            for (auto j{i + 1}; j < len; j++) {
                for (auto k{j + 1}; k < len; k++) {
                    const auto cond1{abs(arr[i] - arr[j])};
                    const auto cond2{abs(arr[j] - arr[k])};
                    const auto cond3{abs(arr[i] - arr[k])};
                    
                    if (cond1 <= a && cond2 <= b && cond3 <= c) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
