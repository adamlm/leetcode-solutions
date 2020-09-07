class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if (trust.empty() && N == 1) {
            return 1;
        }
        
        unordered_set<int> truster;
        unordered_map<int, int> trusted;
        
        for (const auto p: trust) {
            truster.insert(p[0]);
            trusted[p[1]]++;
        }
        
        for (const auto [k, v]: trusted) {
            if (truster.find(k) == truster.end() && v == N - 1) {
                return k;
            }
        }
        
        return -1;
    }
};
