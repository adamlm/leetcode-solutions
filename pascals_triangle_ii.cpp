class Solution {
public:
    vector<int> getRow(int rowIndex) {
        auto i{1};
        vector<int> output;
        vector<int> prev;
        
        output.push_back(1);
        
        while (i <= rowIndex) {
            output.clear();
            output.push_back(1);
            
            for (auto j{1}; j < i; j++) {
                output.push_back(prev[j - 1] + prev[j]);
            }
            
            output.push_back(1);
            prev = output;
            i++;
        }
        
        return output;
    }
};
