//https://leetcode.com/problems/factorial-trailing-zeroes/
class Solution {
public:
    int trailingZeroes(int n) {
        //2147483647
        int count5 = 0;
        unsigned long long val = 5;
        while (val <= n) {
            count5 += n / val;
            val *= 5;
        }
        return count5;
    }
};
