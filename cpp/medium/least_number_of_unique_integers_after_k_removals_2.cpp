class Solution {    
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mCounts;
        priority_queue<int, vector<int>, greater<int>> qCounts;
        
        for (const auto n: arr) {
            mCounts[n]++;
        }
        
        for (const auto& kv: mCounts) {
            qCounts.push(kv.second);
        }
        
        while (k > 0) {
            const auto top{qCounts.top()};
            
            if (top <= k) {
                k -= top;
                qCounts.pop();
            } else {
                break;
            }
        }
        
        return qCounts.size();
    }
};
