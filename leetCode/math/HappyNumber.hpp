//https://leetcode.com/problems/happy-number/
class Solution {
public:
    inline int digitSum(int n) {
        int value = (n % 10) * (n % 10);
        while (n) {
            n /= 10;
            value += (n % 10) * (n % 10);
        }
        return value;
    }

    bool isHappy(int n) {
        set<int> nums;
        while (n != 1 && nums.find(n) == nums.end()) {
            nums.emplace(n);
            n = digitSum(n);
        }
        return n == 1;
    }
};
