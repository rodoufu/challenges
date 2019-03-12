//https://leetcode.com/problems/monotonic-array/
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() < 2) {
            return true;
        }
        int ini = 0;
        int size = A.size();
        while (ini < size - 1 && A[ini] == A[ini + 1]) {
            ++ini;
        }
        if (ini == size - 1) {
            return true;
        }
        bool bigger = A[ini] <= A[ini + 1];
        
        if (bigger) {
            for (int i = ini; i < size - 1; ++i) {
                if (A[i] > A[i + 1]) {
                    return false;
                }
            }
        } else {
            for (int i = 1; i < size - 1; ++i) {
                if (A[i] < A[i + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
