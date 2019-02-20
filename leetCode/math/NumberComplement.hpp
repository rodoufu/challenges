//https://leetcode.com/problems/number-complement/
class Solution {
public:
    int findComplement(int num) {
        long long numLong = num;
        int bits = 0;
        while (numLong) {
            ++bits;
            numLong >>= 1;
        }
        numLong = ~num;
        return numLong & ((1L << bits) - 1);
    }
};
