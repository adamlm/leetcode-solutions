class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {        
        vector<int> ret;
        vector<int> deltas;
        auto xor_sum{0};
        
        for (const auto& a: arr) {
            xor_sum ^= a;
            deltas.push_back(xor_sum);
        }
        
        for (const auto& q: queries) {
            auto begin{q[0]};
            auto end{q[1]};
            
            ret.push_back(arr[begin] ^ (deltas[begin] ^ deltas[end]));
        }
        
        return ret;
    }
};
