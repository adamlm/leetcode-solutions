class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        auto largest{arr[0]};
        auto count{0};
        
        for (auto i{1}; i < arr.size(); i++) {
            if (arr[i] > largest) {
                largest = arr[i];
                count = 1;
            } else {
                count++;
            }
            
            if (count >= k) {
                break;
            }
        }
        
        return largest;
    }
};
