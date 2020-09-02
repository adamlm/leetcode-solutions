class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string output = "";
        sort(A.begin(), A.end());
        
        do {
            output = maxValid(A, output);
        } while (next_permutation(A.begin(), A.end()));
        
        return output;
    }

private:
    string maxValid(vector<int>& A, string output) {       
        if (!((A[0] < 2 && A[1] <= 9 || A[0] == 2 && A[1] <= 3) && A[2] <= 5 && A[3] <= 9)) {
            return output;
        }
        
        string t = to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
        
        return max(output, t);
    }
};
