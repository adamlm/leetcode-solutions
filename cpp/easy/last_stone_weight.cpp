class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.end());
        
        while (q.size() > 1) {
            auto y{q.top()};
            q.pop();
            const auto x{q.top()};
            q.pop();
            
            if (x != y) {
                y -= x;
                q.push(y);
            }
        }
        
        return q.empty()? 0: q.top();
    }
};
