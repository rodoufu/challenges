// https://leetcode.com/problems/guess-number-higher-or-lower/
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        unsigned int l = 0, r = n, m = 0;
        int v = 0;
        while (l <= r) {
            m = (l + r) / 2;
            v = guess(m);
            //printf("v:%+d,l:%llu,m:%llu,r:%llu\n", v, l, m, r);
            if (v > 0) {
                l = m + 1;
            } else if (v < 0) {
                r = m - 1;
            } else {
                return m;
            }
        }
        return -1;
    }
};
