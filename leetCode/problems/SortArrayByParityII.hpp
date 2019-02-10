// https://leetcode.com/problems/sort-array-by-parity-ii/
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> odd, even;
        auto end = A.end();
        for (auto it = A.begin(); it != end; ++it) {
            if (*it % 2) {
                odd.push_back(*it);
            } else {
                even.push_back(*it);
            }
        }
        int size = A.size();
        int iodd = 0, ieven = 0;
        for (int i = 0; i < size; ++i) {
            if (i % 2) {
                A[i] = odd[iodd++];
            } else {
                A[i] = even[ieven++];
            }
        }
        return A;
    }
};
