class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> output;
        
        for (auto i{1}; i <= n; i++) {
            string s;
            
            if (i % 3 == 0) {
                s.append("Fizz");
            }
            
            if (i % 5 == 0) {
                s.append("Buzz");
            }
            
            if (s.empty()) {
                s.append(to_string(i));
            }
            
            output.push_back(s);
        }
        
        return output;
    }
};
