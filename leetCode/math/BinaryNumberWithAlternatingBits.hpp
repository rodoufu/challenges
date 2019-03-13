// https://leetcode.com/problems/binary-number-with-alternating-bits/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        if (n == 0 || n == -1) {
            return false;
        }
        //printf("%d\n", n);
        int value = n & 1;
        n >>= 1;
        while (n && n != -1) {
            //printf("%d\n", n);
            if (!((n ^ value) & 1)) {
                return false;
            }
            value = n & 1;
            n >>= 1;
        }
        return true;
    }
};
