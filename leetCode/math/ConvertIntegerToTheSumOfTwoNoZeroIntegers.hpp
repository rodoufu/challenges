// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
class Solution {
private:
    inline bool hasZero(int n) {
        if (n == 0) { 
            return true;
        }
        while (n) {
            if (n % 10 == 0) {
                return true;
            }
            n /= 10;
        }
        return false;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i <= n / 2; ++i) {
            if (!hasZero(i) && !hasZero(n - i)) {
                return vector<int>({i, n - i});
            }
        }
        return vector<int>();
    }
};
