class Solution {
public:
    int mySqrt(int x) {
        unsigned long long resp = 1;
        for (unsigned long long i = 0; i <= x; ++i) {
            if (i * i <= x) {
                resp = i;
            } else {
                break;
            }
        }
        return resp;
    }
};
