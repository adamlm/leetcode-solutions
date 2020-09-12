class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        auto i{static_cast<int>(A.size() - 1)};
        auto carry{0};
        
        while (K > 0 || carry > 0) {
            if (i < 0) {
                A.insert(A.begin(), 0);
                i = 0;
            }
            A[i] += K % 10 + carry;
            carry = A[i] / 10;
            A[i] %= 10;
            K /= 10;
            i--;
        }
        
        return A;
    }
};
