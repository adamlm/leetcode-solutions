class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        
        sort(arr.begin(), arr.end());
        const auto median{arr[(arr.size() - 1) / 2]};
        
        sort(arr.begin(), arr.end(), [median](const int a, const int b) -> bool {
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
            
        vector<int> output(arr.begin(), arr.begin() + k);
        return output;
    }
};
