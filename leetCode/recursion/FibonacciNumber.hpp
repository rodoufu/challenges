//https://leetcode.com/problems/fibonacci-number/
class Solution {
public:
    int fib(int N) {
        if (N == 0) {
            return 0;
        }
        if (N <= 2) {
            return 1;
        }
        int fib[] = {0, 1, 1};
        for (int i = 2; i < N; ++i) {
            fib[0] = fib[1];
            fib[1] = fib[2];
            fib[2] = fib[0] + fib[1];
        }
        return fib[2];
    }
};
