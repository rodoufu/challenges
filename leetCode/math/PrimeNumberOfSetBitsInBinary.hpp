//https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
class Solution {
public:
    inline bool isPrime(int x) {
        if (x <= 2) {
            return x == 2;
        }
        if (x % 2 == 0) {
            return false;
        }
        int max = sqrt(x);
        for (int i = 2; i <= max; ++i) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    int countPrimeSetBits(int L, int R) {
        int nb, count = 0;
        for (int i = L; i <= R; ++i) {
            //printf("%d:[%d]->%d\n", i, numBits(i), isPrime(numBits(i)));
            nb = __builtin_popcount(i);
            count += isPrime(nb) ? 1 : 0;
        }
        return count;
    }
};
