class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        
        nth_element(arr.begin(), arr.begin() + (arr.size() - 1) / 2, arr.end());
        const auto median{arr[(arr.size() - 1) / 2]};
        
        nth_element(arr.begin(), arr.begin() + k, arr.end(), [median](const int a, const int b) -> bool {
            const auto dA = abs(a - median);
            const auto dB = abs(b - median);
            
            if (dA > dB) {
                return 1;
            }
            
            if (dA < dB) {
                return 0;
            }
            
            return a > b;
        });

        return {arr.begin(), arr.begin() + k};
    }
};
