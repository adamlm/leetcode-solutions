class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto count{0};
        
        for (auto start{0}; count < nums.size(); start++) {
            auto current = start;
            auto prev{nums[start]};
            
            do {
                auto next{(current + k) % nums.size()};
                auto tmp{nums[next]};
                nums[next] = prev;
                prev = tmp;
                current = next;
                count++;
            } while (current != start);
        }
    }
};
