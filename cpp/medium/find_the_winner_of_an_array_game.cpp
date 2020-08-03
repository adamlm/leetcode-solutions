class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        queue<int> q;
        auto prev{arr[0]};
        auto count{0};
        
        for (auto i{1}; i < arr.size(); i++) {
            q.push(arr[i]);
        }
        
        while (count < k && count < arr.size() - 1) {
            const auto current{max(q.front(), prev)};
            
            if (current == prev) {
                q.push(q.front());
                count++;
            } else {
                q.push(prev);
                count = 1;
            }
            
            q.pop();
            prev = current;
        }
        
        return prev;
    }
};
