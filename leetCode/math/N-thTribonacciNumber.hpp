// https://leetcode.com/problems/n-th-tribonacci-number/
class Solution {
public:
    int tribonacci(int n) {
        if (!n)
            return 0;
        if (n < 3) {
            return 1;
        }
        int a = 1, b = 1, c = 1, d = 2;
        for (int i = 3; i < n; ++i) {
            a = b;
            b = c;
            c = d;
            d = a + b + c;
        }
        return d;
    }
};
