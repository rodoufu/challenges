class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        int count = 0;
        while (x) {
            x &= x - 1;
            ++count;
        }
        return count;
    }
};
