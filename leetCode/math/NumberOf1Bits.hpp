//https://leetcode.com/problems/number-of-1-bits/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bitsOne = 0;
        for (int i = 0; i < 32; i++) {
            bitsOne += n & 1;
            n >>= 1;
        }
        return bitsOne;
    }
};
