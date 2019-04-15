// https://leetcode.com/problems/smallest-range-i/
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int min_v = *min_element(A.begin(), A.end());
        int max_v = *max_element(A.begin(), A.end());
        if (!K) {
            return max_v - min_v;
        }
        return max(max_v - min_v - 2 * K, 0);
    }
};
