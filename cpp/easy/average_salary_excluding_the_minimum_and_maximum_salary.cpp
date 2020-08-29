class Solution {
public:
    double average(vector<int>& salary) {
        const auto size{static_cast<int>(salary.size()) - 2};
        
        sort(salary.begin(), salary.end());
        
        return accumulate(salary.begin() + 1, salary.end() - 1, 0.0) / size;
    }
};
