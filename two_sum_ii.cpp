class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> output;
        
        for (auto i{0}; i < numbers.size(); i++) {
            auto ret = binarySearch(numbers, i + 1, numbers.size(), target - numbers[i]);
            
            if (ret != -1) {
                output.push_back(i + 1);
                output.push_back(ret + 1);
                break;
            }
        }
        
        return output;
    }
    
    int binarySearch(vector<int>& numbers, int start, int end, int target) {
        if (start >= end) {
            return -1;
        }
        
        auto middle = (end + start) / 2;
        
        if (numbers[middle] == target) {
            return middle;
        }
        
        if (numbers[middle] > target) {
            return binarySearch(numbers, start, middle, target);
        }
        
        return binarySearch(numbers, middle + 1, end, target);
    }
};
