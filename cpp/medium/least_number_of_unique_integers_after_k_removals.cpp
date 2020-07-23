class Solution {
private:
    struct pairComp {
        constexpr bool operator() (pair<int, int> const& a, pair<int, int> const& b) {
            return a.second > b.second;
        }
    };
    
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mCounts;
        priority_queue<pair<int, int>, vector<pair<int, int>>, pairComp> qCounts;
        
        for (const auto n: arr) {
            mCounts[n]++;
        }
        
        for (const auto& kv: mCounts) {
            qCounts.push({kv.first, kv.second});
        }
        
        while (k > 0) {
            const auto top{qCounts.top()};
            
            if (top.second <= k) {
                k -= top.second;
                qCounts.pop();
            } else {
                break;
            }
        }
        
        return qCounts.size();
    }
};
