class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> output;
        auto start = numbers.begin();
        auto end = numbers.end() - 1;
        
        while (start < end) {
            auto sum = *start + *end;
            
            if (sum == target) {
                output.push_back(start - numbers.begin() + 1);
                output.push_back(end - numbers.begin() + 1);
                break;
            }
            
            if (sum < target) {
                start++;
            } else {
                end--;
            }
        }
        
        return output;
    }
};
