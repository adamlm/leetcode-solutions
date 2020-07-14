class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;
        
        if (numRows == 0) {
            return output;
        }
        
        output.emplace_back(vector<int>{1});
        
        for (auto i = 1; i < numRows; i++) {
            vector<int> row;
            
            for (auto j = 0; j <= i; j++) {
                if (j == 0) {
                    row.push_back(output[i - 1][j]);
                } else if (j == i) {
                    row.push_back(output[i - 1][j - 1]);
                } else {
                    row.push_back(output[i - 1][j - 1] + output[i - 1][j]);
                }
            }
            
            output.push_back(row);
        }
        
        return output;
    }
};
