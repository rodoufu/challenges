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
    
    inline int numBits(int x) {
        int cont = 0;
        while (x) {
            if (x & 1) {
                ++cont;
            }
            x >>= 1;
        }
        return cont;
    }

    int countPrimeSetBits(int L, int R) {
        int nb, count = 0;
        for (int i = L; i <= R; ++i) {
            //printf("%d:[%d]->%d\n", i, numBits(i), isPrime(numBits(i)));
            nb = numBits(i);
            count += isPrime(nb) ? 1 : 0;
        }
        return count;
    }
};
