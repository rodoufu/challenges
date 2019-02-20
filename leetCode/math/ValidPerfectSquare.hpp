//https://leetcode.com/problems/valid-perfect-square/
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) {
            return false;
        }
        if (num == 1) {
            return true;
        }
        unsigned long long temp;
        for (unsigned long long i = 0; i <= num / 2; ++i) {
            temp = i * i;
            if (temp == num) {
                return true;
            }
            if (temp > num) {
                break;
            }
        }
        return false;
    }
};
