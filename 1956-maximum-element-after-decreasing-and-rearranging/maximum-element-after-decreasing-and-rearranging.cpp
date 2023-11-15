class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& A) {
    sort(A.begin(), A.end());
    A[0] = 1;
    for (int i = 1; i < A.size(); ++i) {
        A[i] = min(A[i - 1] + 1, A[i]);
    }
    return A.back();        
    }
};