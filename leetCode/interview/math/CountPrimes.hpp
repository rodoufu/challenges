class Solution {
public:
    int countPrimes(int n) {
        if (n < 1) {
            return 0;
        }
        bool *primes = new bool[n];
        for (int i = 0; i < n; ++i) {
            primes[i] = true;
        }
        int it = 2;
        int cont = 0;
        while (it < n) {
            ++cont;
            for (int i = it; i < n; i += it) {
                primes[i] = false;
            }
            while (++it < n) {
                if (primes[it]) {
                    break;
                }
            }
        }
        delete []primes;
        return cont;
    }
};
