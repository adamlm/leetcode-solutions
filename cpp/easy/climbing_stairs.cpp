class Solution {
public:
    int climbStairs(int n) {
        map<int, int> memo;
        
        return climbStairsMemo(n, memo);
    }
    
    int climbStairsMemo(int n, map<int, int>& memo) {
        if (n == 0) {
            return 1;
        }
        
        if (n <= 2) {
            return n;
        }
        
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        
        auto steps{climbStairsMemo(n - 1, memo) + climbStairsMemo(n - 2, memo)};
        memo[n] = steps;
        
        return steps;
    }
};
