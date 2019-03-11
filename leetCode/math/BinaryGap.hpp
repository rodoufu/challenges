// https://leetcode.com/problems/binary-gap/
class Solution {
public:
    int binaryGap(int N) {
        while (N && N % 2 == 0) {
            N >>= 1;
        }
        int count;
        int m = 0;
        while (N) {
            //printf("%d-", N);
            N >>= 1;
            //printf("%d->%d\n", N, N & 1);
            count = 1;
            while (N && N % 2 == 0) {
                //printf("w%d\n", N);
                ++count;
                N >>= 1;
            }
            if (!N) {
                break;
            }
            m = max(m, count);
        }
        return m;
    }
};
