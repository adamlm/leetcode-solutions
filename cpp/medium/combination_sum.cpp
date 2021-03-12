class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> combo;
        
        helper(candidates, target, ret, combo);
        
        return ret;
    }
    
    void helper(const vector<int>& candidates, int target, vector<vector<int>>& ret, vector<int> combo) {        
        if (target == 0) {
            sort(begin(combo), end(combo));
            for (const auto& r: ret) {
                if (r == combo) {
                    return;
                }
            }
            ret.push_back(combo);
            return;
        }
        
        for (const auto c: candidates) {
            if (target - c >= 0) {
                auto new_combo = combo;
                new_combo.push_back(c);
                helper(candidates, target - c, ret, new_combo);
            }
        }
    }
};
