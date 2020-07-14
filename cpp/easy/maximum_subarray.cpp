class Solution {
public:
    int maxSubArray(vector<int>& nums) {    
        auto sum{nums[0]};
        auto maxSum{sum};
        
        for (auto num{nums.begin() + 1}; num != nums.end(); num++) {
            sum = (sum > 0? sum : 0) + *num;
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};
