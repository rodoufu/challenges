// https://leetcode.com/problems/complement-of-base-10-integer/
class Solution {
public:
    int bitwiseComplement(int N) {
        if (!N) {
            return 1;
        }
        N = N < 0 ? -N : N;
        int resp = 0;
        for (int i = 0; N; ++i) {
            resp += (~N & 1) << i;
            N >>= 1;
        }
        return resp;
    }
};
