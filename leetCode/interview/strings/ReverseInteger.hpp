//https://leetcode.com/problems/reverse-integer/
class Solution {
public:
    int reverse(int x) {
        long long resp = 0;
        long long y = x > 0 ? x : -x;
        while (y > 0) {
            resp *= 10;
            resp += y % 10;
            y /= 10;
        }
        resp = resp > (1LL << 32 - 1) ? 0 : resp;
        return (int)(x < 0 ? -resp : resp);
    }
};
